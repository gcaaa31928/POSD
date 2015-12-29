//
// Created by Red on 2015/12/29.
//

#ifndef VISITOR1013_2015_VIEWS_H
#define VISITOR1013_2015_VIEWS_H


#include "Observer.h"

class Views : public Observer {

public:
    virtual void update(void *pVoid) = 0;
};

#endif //VISITOR1013_2015_VIEWS_H
