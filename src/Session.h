#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>

#include <QThread> // for QThread::sleep
#include <QDebug>
#include <vector>

#include "EEG.h"
using namespace std;

/* Purpose of class: Session object to hold information about a session
 *
 * Data Members:
 *
 * - QString sessionName: a QString representation of the Sessions name
 * - QTimer* timer: A QTimer object to keep track of how long a session should last
 *
 * -int time: A integer representation of how long a session lasts
 * -QDateTime startTime: A integer representation of the start time and date of the session
 * -QDateTime endTime: A integer representation of the end time and date of the session
 *
 * -QList<int> startAverage: QList of integers that repersent baseline dominant frequencey start averages for each of the EEG sites
 * -QList<int> endAverage: QList of integers that repersent baseline dominant frequencey end averages for each of the EEG sites
 *
 *
 * Class functions:
 * -getters for data members
 */

class Session: public QObject {
    Q_OBJECT

public:
    Session(QVector<EEG*> eegList);
    ~Session();

    QString getName();
    QTimer* getTimer();
    int getId();

    int getTime();
    QDateTime getStartTime();
    QDateTime getEndTime();

    QVector<int> getStartAverages();
    QVector<int> getEndAverages();
    int getCurrentRound();

    void startSession();

    void playSession();
    void pauseSession();
    void stopSession();

    void initBools(bool eegs[]);
    void greenLightOn();

private:

    int numRounds;
    int currentRound;

    int time;
    int currentSiteIndex;

    int calculationTime;

    QTimer* timer;
    QTimer* currentTimer;
    QString sessionName;

    QVector<EEG*> eegList;
    bool* eegConnections;
    vector<bool> connections;

    QDateTime startTime;
    QDateTime endTime;
    bool checkIfConnectionLost();

    QVector<int> startAverages; // Store start averages for each of the 21 EEG sites
    QVector<int> endAverages; // Store end averages for each of the 21 EEG sites

    static int idCounter; // Keeps track of the number of Session objects created
    int id; // Stores the unique id for each Session object

    QVector<int> calculateBaselineAvg();
    void startRound();
    void startTreatment();

    void greenLightOff();
    void informUser();



    int getElapsedTime();
signals:
    void turnOnGreen(bool);
    void turnOnRed(bool);
    void sessionEnded();
    void turnOff();
};

#endif // SESSION_H
