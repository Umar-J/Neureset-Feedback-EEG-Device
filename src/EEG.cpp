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

void EEG::updateBaseline(int newBaseline){
    this->baseline = newBaseline;
}

int EEG::getId() const
{
    return id;
}
