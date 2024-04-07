#ifndef EEG_H
#define EEG_H

#include <QRandomGenerator>
#include <QVector>
#include <QPair>
#include <QtCharts>

/* Purpose of class: repersents an individual EEG site
 *
 * Data Members:
 * - int id: an integer repersentation of the EEG id (between 1 and 21)
 *
 * Class functions:
 * - getBaseline():  calculates the baseline dominant frequencey average for a specific EEG site
 */

class EEG{

public:
    // Define the EEG bands
    enum Band { Alpha, Beta, Delta, Theta, Gamma };

    // Define the EEG waveform structure
    struct EEGWaveform {
        QVector<double> frequencies;
        QVector<double> amplitudes;
        QVector<double> values;
    };

    EEG(int);
    double getBaseline();
    void updateBaseline(int newBaseline);
    int getId() const;
    EEGWaveform waveform;

    void generateWaveforms();
    void deleteWaveforms();
    QChartView* plotWaveform();

    void applyTreatment(double offset);
    void calculateDominantFrequency();

private:
    int id;
    bool isConnected;
    double baseline;

    QVector<QPair<double, double>> frequencyRanges;

};

#endif // EEG_H
