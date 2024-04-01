#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>


/* Purpose of class: Session object to hold information about a session
 *
 * Data Members:
 *
 * - QString sessionName: a QString representation of the Sessions name
 * - QTimer* timer: A QTimer object to keep track of how long a session should last
 *
 * -int time: A integer representation of how long a session lasts
 * -int startTime: A integer representation of the start time and date of the session
 * -int endTime: A integer representation of the end time and date of the session
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
    Session(QString sessionName, int time);
    ~Session();

    QString getName();
    QTimer* getTimer();

    int getTime();
    int getStartTime();
    int getEndTime();

    QVector<int> getStartAverages();
    QVector<int> getEndAverages();

private:
    QTimer* timer;
    QString sessionName;

    int time;
    int startTime;
    int endTime;

    QVector<int> startAverages; // Store start averages for each of the 21 EEG sites
    QVector<int> endAverages; // Store end averages for each of the 21 EEG sites
};

#endif // SESSION_H
