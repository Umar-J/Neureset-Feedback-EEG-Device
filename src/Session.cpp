#include "Session.h"

int Session::idCounter = 0;

Session::Session(QVector<EEG*> eegList){
    //id increment
    id = ++idCounter;

    numRounds = 4;
    currentRound = 1;

    this->currentSiteIndex = 0;

    sessionName = "Session " + QString::number(id);

    currentTimer = new QTimer(this);

    this->eegList = eegList;

    eegConnections = new bool [eegList.size()];

    //Minute * seconds * miliseconds
    //calculationTime = 1 * 60 * 1000;

    //FOR DEMONSTATION
    calculationTime = 5000;
    //qInfo("%d",connections[1]);
    qInfo("ctor called");
}

Session::~Session(){
    delete timer;
}

//getters
QString Session::getName() {return sessionName; }
QTimer* Session:: getTimer() { return timer; }
int Session::getId() {return id; }

QDateTime Session::getStartTime() {return startTime; }
QDateTime Session::getEndTime() {return endTime; }

QVector<int> Session::getStartAverages() {return startAverages;}
QVector<int> Session::getEndAverages() { return endAverages; }


void Session::startSession(){

    //Keeps track of time
    checkIfConnectionLost();
    startTime = QDateTime::currentDateTime();

    //Calculate the overall baseline for all EEG sites concurrently at the start of the session
    qInfo("processing input waveform...");
    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){
        startAverages = calculateBaselineAvg();
        this->startRound();
    });
    currentTimer->start(calculationTime);
}


void Session::playSession(){
    // Start or resume session
    checkIfConnectionLost();
    currentTimer->start();
    startTime = QDateTime::currentDateTime();
}

void Session::pauseSession(){
    //pause the session
    currentTimer->stop();
    endTime = QDateTime::currentDateTime();
    time += getElapsedTime();
}

void Session::stopSession(){
    //Stop session
    currentTimer->stop();
    endTime = QDateTime::currentDateTime();
    time += getElapsedTime();

    // Calculate the overall baseline for all EEG sites concurrently at the end of the session
    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){

        endAverages = calculateBaselineAvg();
        //Inform the user about the session completion
        informUser();

        //resets baseline frequency for next sesison
        for(int i = 0; i< eegList.size(); i++){
            eegList[i]->updateBaseline(-1);
        }

        emit sessionEnded();
    });
    currentTimer->start(calculationTime);
}

void Session::startRound() {

    if(currentRound == 1) qInfo("Processing Complete.");

    checkIfConnectionLost();

// BRING THIS BACK IF RECALCUATION IS NEEDED EVERYTIME (OPTION 1)
//    for(int i = 0; i < eegList.size(); i++){
//        eegList[i]->calculateDominantFrequency();
//    }

    if(currentRound <= 4){
        QString roundMessage = QString("Round %1 of therapy").arg(currentRound);
        qInfo() << roundMessage;
        qInfo("Calculating dominant frequency...");

        qInfo("delivering the 1 sec feedback at 1/16 of dominant + offset...");

        greenLightOn();

        currentTimer->stop();
        currentTimer = new QTimer(this);
        connect(currentTimer, &QTimer::timeout, this, [=](){
            startTreatment();
        });
        currentTimer->start(1000);
    }
    else{
        stopSession();
    }
}

QVector<int> Session::calculateBaselineAvg() {
    checkIfConnectionLost();
    QVector<int> baselineAvg;
    for(int i = 0; i < eegList.size(); i++){
        eegList[i]->calculateDominantFrequency();
        baselineAvg.append(eegList[i]->getBaseline());
        QString message = QString("EEG %1's baseline average: %2").arg(i+1).arg(eegList[i]->getBaseline());
        qInfo() << message;
    }
    currentTimer->stop();

    return baselineAvg;
}


void Session::startTreatment(){
    // Start treatment, flash green light
    checkIfConnectionLost();
    greenLightOff();

    //Treat ALL eeg sites concurrently
    double offset = currentRound * 5;

    for(int i = 0; i < eegList.size(); i++){
        eegList[i]->applyTreatment(offset);
    }

    QString roundMessage = QString("Round %1 Complete.").arg(currentRound);
    qInfo() << roundMessage;

    currentRound++;

    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){
        this->startRound();
    });
    currentTimer->start(calculationTime);
}

void Session::greenLightOn(){
    //MainWindow::treatmentLedHandler();
    emit turnOnGreen(true);
}

void Session::greenLightOff(){
    //MainWindow::treatmentLedHandler();
    emit turnOnGreen(false);
}

void Session::informUser(){
    QString message = QString("Session Complete! Elapsed Time: %1").arg(time);
    qInfo() << message;

    currentTimer->stop();
}

void Session::initBools(bool eegs[]){
    //qInfo("reached here");
    eegConnections = eegs;
    connections = vector<bool>(eegList.size(), false);
    for (int i =0; i< eegList.size();i++){
       //qInfo("EEg at %d is %d",i,eegs[i]);
        connections[i] = eegs[i];
       // qInfo("EEg at %d is %d",i,eegs[i]);
    }
   // qInfo("Now hwere");
}

bool Session::checkIfConnectionLost(){
    for (int i =0; i< eegList.size();i++){
        if (eegConnections[i] == false){
            stopSession();
            //call mainwindow stop session
            qInfo("eeg %d is disconnected-------------------------------",i);
            //make it red
            emit turnOnRed(true);
            return true;
        }

    }
    emit turnOnRed(false);
    return false;
}

int Session::getElapsedTime() {
    int inSeconds = 1000;
    //int inMinutes = 60000;

    qint64 elapsedTimeInMilliseconds = startTime.msecsTo(endTime);
    int elapsedTime = static_cast<int>(elapsedTimeInMilliseconds / inSeconds);
    return elapsedTime;
}



