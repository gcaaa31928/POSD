//
// Created by Red on 2015/12/29.
//

#ifndef VISITOR1013_2015_SUBJECT_H
#define VISITOR1013_2015_SUBJECT_H


#include "Observer.h"
#include <vector>
using namespace std;

class Subject {
public:
    void addObserver(Observer *observer);

protected:
    void notifyObservers();
    vector<Observer *> observers;

};
#endif //VISITOR1013_2015_SUBJECT_H
