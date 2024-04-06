#include "Session.h"

int Session::idCounter = 0;

Session::Session(QVector<EEG*> eegList){
    //id increment
    id = ++idCounter;

    this->currentSiteIndex = 0;

    sessionName = "Session " + QString::number(id);

    currentTimer = new QTimer(this);

    this->eegList = eegList;

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

    //Calculate the overall baseline for all 21 EEG sites concurrently at the start of the session
    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){
        startAverages = calculateBaselineAvg();

        // Calculate the baseline frequency for the current EEG site in the span of calculationTime
        currentTimer->stop();
        currentTimer = new QTimer(this);
        connect(currentTimer, &QTimer::timeout, this, [=](){
            this->calculateBaselineFrequency();
        });
        currentTimer->start(calculationTime);

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

    // Calculate the overall baseline for all 21 EEG sites concurrently at the end of the session
    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){

        endAverages = calculateBaselineAvg();
        //Inform the user about the session completion
        informUser();
    });
    currentTimer->start(calculationTime);

}

QVector<int> Session::calculateBaselineAvg() {
    checkIfConnectionLost();
    QVector<int> baselineAvg;
    for(int i = 0; i < eegList.size(); i++){
        baselineAvg.append(eegList[i]->getBaseline());

        QString message = QString("EEG %1's baseline average: %2").arg(i).arg(eegList[i]->getBaseline());
        qInfo() << message;
    }

    currentTimer->stop();

    return baselineAvg;
}


void Session::calculateBaselineFrequency() {

    //recursively calls calculate 21 times
    checkIfConnectionLost();
    if(currentSiteIndex < 20){

        EEG* site = eegList[currentSiteIndex];

        //Gets baseline Frequency
        int baselineFrequency = site->getBaseline();

        qInfo("CALCULATION DONE");

        //When done calculating Start Treatment
        startTreatment(baselineFrequency, site);

    }
    else{
        stopSession();
    }

}

void Session::startTreatment(int frequency, EEG* site){
    // Start treatment, flash green light
    checkIfConnectionLost();
    greenLightOn();


    // Recalculate the brainwave frequency every 1/16th of a second, 16 times (duration of a second)
    currentTimer->stop();
    currentTimer = new QTimer(this);
    connect(currentTimer, &QTimer::timeout, this, [=](){
        recalculateBrainwaveFrequency(frequency, site, 1);
    });
    currentTimer->start(63);
}


void Session::recalculateBrainwaveFrequency(int frequency, EEG* site, int numRecalculations) {
    //add an offset frequency of 5hz to the baseline frequency
    if(checkIfConnectionLost()){
        qInfo("eeg disconnected,returning");
        return;
    }
    frequency = frequency + 5;

    //Updates baseline frequency
    site->updateBaseline(frequency);

    qInfo("RECALCULATION DONE");

    //recursively calls recalculate 16 times
    if(numRecalculations < 16){
        currentTimer->stop();
        currentTimer = new QTimer(this);
        connect(currentTimer, &QTimer::timeout, this, [=](){
            recalculateBrainwaveFrequency(site->getBaseline(), site, numRecalculations + 1);
        });
        currentTimer->start(63);
    }

    if(numRecalculations == 16){
        // flash green light
        greenLightOff();

        //Treatment done, go to next site
        currentSiteIndex++;

        currentTimer->stop();
        currentTimer = new QTimer(this);
        connect(currentTimer, &QTimer::timeout, this, [=](){
            this->calculateBaselineFrequency();
        });
        currentTimer->start(calculationTime);
    }
}

void Session::greenLightOn(){
    //MainWindow::treatmentLedHandler();
}

void Session::greenLightOff(){
    //MainWindow::treatmentLedHandler();
}

void Session::informUser(){
    QString message = QString("Session Complete! Elapsed Time: %1").arg(time);
    qInfo() << message;
}

void Session::initBools(bool eegs[]){
    //qInfo("reached here");
    eegConnections = eegs;
    connections = vector<bool>(21, false);
    for (int i =0; i< 21;i++){
       //qInfo("EEg at %d is %d",i,eegs[i]);
        connections[i] = eegs[i];
       // qInfo("EEg at %d is %d",i,eegs[i]);
    }
   // qInfo("Now hwere");
}

bool Session::checkIfConnectionLost(){
    for (int i =0; i< 21;i++){
        if (eegConnections[i] == false){
            stopSession();
            qInfo("eeg %d is disconnected-------------------------------",i);
            return true;
        }

    }
    return false;
}

int Session::getElapsedTime() {
    int inSeconds = 1000;
    int inMinutes = 60000;

    qint64 elapsedTimeInMilliseconds = startTime.msecsTo(endTime);
    int elapsedTime = static_cast<int>(elapsedTimeInMilliseconds / inSeconds);
    return elapsedTime;
}

