#ifndef EEG_H
#define EEG_H

/* Purpose of class: repersents an individual EEG site
 *
 * Data Members:
 * - int id: an integer repersentation of the EEG id (between 1 and 21)
 *
 * Class functions:
 * - getBaseline():  calculates the baseline dominant frequencey average for a specific EEG site
 */

class EEG
{
public:
    EEG(int);

    int getBaseline();

    int getId() const;

private:
    int id;
    bool isConnected;
};

#endif // EEG_H
