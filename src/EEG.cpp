#include "EEG.h"

EEG::EEG(int id): id(id){

    //returns random baseline frequency initially
    //this->baseline = QRandomGenerator::global()->bounded(1, 101);

    //FOR TESTING
    this->baseline = id;

}

int EEG::getBaseline(){
    return baseline;
}

int EEG::getId() const
{
    return id;
}
