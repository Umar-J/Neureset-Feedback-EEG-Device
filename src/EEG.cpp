#include "EEG.h"

EEG::EEG(int id):
    id(id),
    frequencyRanges({{8, 12}, {12, 30}, {1, 4}, {4, 8}, {25, 140}}){

    //FOR TESTING
    this->baseline = -1;
}

void EEG::generateWaveforms(){
    //Generates random frequencies and amplitudes for the 4 bands.
    int numBands = 4;
    for(int i = 0; i < numBands; i++){
        //allows QRandomGenerator to generate a random frequency between first and second
        double range = frequencyRanges[i].second - frequencyRanges[i].first;
        //frequency for Band i
        double fi = frequencyRanges[i].first + QRandomGenerator::global()->generateDouble() * range;
        //amplitude for Band i
        double ai = QRandomGenerator::global()->generateDouble();

        waveform.frequencies.append(fi);
        waveform.amplitudes.append(ai);
    }

    // Calculate the sum of the 4 sine waves for a range of t values
    for (double t = 0; t <= 1; t += 0.01) {
        double value = 0;
        for(int i = 0; i < waveform.frequencies.size(); i++){
            value += waveform.amplitudes[i] * sin(2 * M_PI * waveform.frequencies[i] * t);
        }
        waveform.values.append(value);
    }

    //double value = A1 * sin(2 * M_PI * f1 * t) + A2 * sin(2 * M_PI * f2 * t) 4+ A3 * sin(2 * M_PI * f3 * t) + A4 * sin(2 * M_PI * f4 * t);
}

void EEG::deleteWaveforms(){
    waveform.frequencies.clear();
    waveform.amplitudes.clear();
    waveform.values.clear();
}

QChartView* EEG::plotWaveform(){
    //If there are no values to plot return
    if (waveform.values.size() == 0) return nullptr;

    // Create a new line series
    QLineSeries* series = new QLineSeries();

    // Add the waveform values to the series
    for (int i = 0; i < waveform.values.size(); ++i) {
        series->append(i, waveform.values[i]);
    }

    // Create a chart and add the series to it
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Create a chart view and set the chart as its scene
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Show the chart view in new window
    //chartView->show();

    return chartView;

}

void EEG::calculateDominantFrequency(){
    //REMOVE THIS IF RECALCUATION IS NEEDED EVERYTIME (OPTION 1)
    //if(baseline != -1) return;

    double numerator = 0;
    double denominator = 0;
    for(int i = 0; i < waveform.frequencies.size(); i++){
        numerator += waveform.frequencies[i] * pow(waveform.amplitudes[i], 2);
        denominator += pow(waveform.amplitudes[i], 2);
    }

    // Handle division by zero error
    if(denominator == 0){
        return;
    }

    this->baseline = numerator/denominator;
}

void EEG::applyTreatment(double offset){
    //OPTION 1
    for(int i = 0; i < waveform.frequencies.size(); i++){
        waveform.frequencies[i] += offset;
    }
    calculateDominantFrequency();

    //OPTION 2 (i think this is correct)
    //this->baseline += offset;
}

double EEG::getBaseline(){
    return this->baseline;
}

void EEG::updateBaseline(int newBaseline){
    this->baseline = newBaseline;
}

int EEG::getId() const
{
    return id;
}
