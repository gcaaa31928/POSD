//
// Created by Red on 2015/12/29.
//

#include "Subject.h"

void Subject::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void Subject::notifyObservers() {
    for(int i =0;i<observers.size();i++){
        observers[i]->update(this);
    }
}


