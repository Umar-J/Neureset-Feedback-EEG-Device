#include "Session.h"

int Session::idCounter = 0;

Session::Session(){
    //id increment
    id = ++idCounter;

    //initialize the timer
    timer = new QTimer(this);

    this->currentSiteIndex = 0;

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

QList<int> Session::getStartAverages() {return startAverages;}
QList<int> Session::getEndAverages() { return endAverages; }


void Session::startSession(QVector<EEG*> eegList){

    //Opens timer once contact with electrodes is established
    timer->start();
    startTime = QDateTime::currentDateTime();

    //Calculate the overall baseline for all 21 EEG sites concurrently at the start of the session
    startAverages = calculateBaselineAvg(eegList);


//     // Set the duration for baseline frequency calculation
//     int baselineFrequencyDuration = 1;


//    // Calculate the baseline frequency for the current EEG site in the span of 1 minute
//    QTimer::singleShot(baselineFrequencyDuration * 60 * 1000, this, [=]() {
//        this->calculateBaselineFrequency(eegList);
//    });


    //FOR DEMONSTATION calculation will be 5 seconds
    QTimer::singleShot(5000, this, [=]() {
        this->calculateBaselineFrequency(eegList);
    });


}


void Session::playSession(){
    if(!timer->isActive()){
        // Start or resume session
        timer->start();
        startTime = QDateTime::currentDateTime();
    }
}

void Session::pauseSession(){
    // check if the session is running
    if(timer->isActive()){
        //pause the session
        timer->stop();
        endTime = QDateTime::currentDateTime();

        time += getElapsedTime();
    }
}

void Session::stopSession(){

    //Check if session is running
    if(timer->isActive()){
        //Stop session
        timer->stop();
        endTime = QDateTime::currentDateTime();
        time += getElapsedTime();

        //Inform the user about the session completion
        informUser();
    }

}

QList<int> Session::calculateBaselineAvg(QVector<EEG*> eegList) {

}


void Session::calculateBaselineFrequency(QVector<EEG*> eegList) {

    EEG* site = eegList[currentSiteIndex];

    //Gets baseline Frequency
    int baselineFrequency = site->getBaseline();

    qInfo("CALCULATION DONE");

    //When done calculating Start Treatment
    startTreatment(baselineFrequency);

    //recursively calls calculate 21 times
    if(currentSiteIndex < 20){

        currentSiteIndex++;

        QTimer::singleShot(5000, this, [=]() {
            calculateBaselineFrequency(eegList);
        });
    }
    else{
        // Calculate the overall baseline for all 21 EEG sites concurrently at the end of the session
        endAverages = calculateBaselineAvg(eegList);

        stopSession();
    }

}

void Session::startTreatment(int frequency){
    // Start treatment, flash green light
    greenLightOn();

    // Recalculate the brainwave frequency every 1/16th of a second, 16 times (duration of a second)
    QTimer::singleShot(63, this, [=]() {
        recalculateBrainwaveFrequency(frequency, 1);
    });
}


void Session::recalculateBrainwaveFrequency(int frequency, int numRecalculations) {
    //add an offset frequency of 5hz to the baseline frequency
    frequency = frequency + 5;

    //Does the recalculation
    int recalculatedFrequency = frequency;

    qInfo("RECALCULATION DONE");

    //recursively calls recalculate 16 times
    if(numRecalculations < 16){
        QTimer::singleShot(63, this, [=]() {
            recalculateBrainwaveFrequency(recalculatedFrequency, numRecalculations + 1);
        });
    }

    if(numRecalculations == 16){
        // flash green light
        greenLightOff();
    }
}

void Session::greenLightOn(){
    //MainWindow::treatmentLedHandler()
}

void Session::greenLightOff(){
    //MainWindow::treatmentLedHandler()
}

void Session::informUser(){
    QString message = QString("Session Complete! Elapsed Time: %1").arg(time);
    qInfo() << message;
}

int Session::getElapsedTime() {
    qint64 elapsedTimeInMilliseconds = startTime.msecsTo(endTime);
    int elapsedTimeInMinutes = static_cast<int>(elapsedTimeInMilliseconds / 60000);
    return elapsedTimeInMinutes;
}

