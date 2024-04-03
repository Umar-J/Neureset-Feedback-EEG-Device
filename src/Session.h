#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>

#include <QThread> // for QThread::sleep
#include <QDebug>

#include "EEG.h"


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
    Session();
    ~Session();

    QString getName();
    QTimer* getTimer();
    int getId();

    int getTime();
    QDateTime getStartTime();
    QDateTime getEndTime();

    QList<int> getStartAverages();
    QList<int> getEndAverages();

    void startSession(QVector<EEG*> eegList);

    void playSession();
    void pauseSession();
    void stopSession();

private:
    int time;
    int currentSiteIndex;

    QTimer* timer;
    QString sessionName;

    QDateTime startTime;
    QDateTime endTime;

    QList<int> startAverages; // Store start averages for each of the 21 EEG sites
    QList<int> endAverages; // Store end averages for each of the 21 EEG sites

    static int idCounter; // Keeps track of the number of Session objects created
    int id; // Stores the unique id for each Session object

    QList<int> calculateBaselineAvg(QVector<EEG*> eegList);
    void startTreatment(int frequency);
    void calculateBaselineFrequency(QVector<EEG*> eegList);
    void recalculateBrainwaveFrequency(int frequency, int numRecalculations);

    void greenLightOn();
    void greenLightOff();
    void informUser();

    int getElapsedTime();

};

#endif // SESSION_H
