#include "Session.h"

Session::Session(QString name, int t){

    sessionName = name;
    time = t;

    //initialize the timer
    timer = new QTimer(this);
}

Session::~Session(){
    delete timer;
}

//getters
QString Session::getName() {return sessionName; }
QTimer* Session:: getTimer() { return timer; }

int Session::getTime() {return time; }
int Session::getStartTime() {return startTime; }
int Session::getEndTime() {return endTime; }

QVector<int> Session::getStartAverages() {return startAverages; }
QVector<int> Session::getEndAverages() { return endAverages; }
