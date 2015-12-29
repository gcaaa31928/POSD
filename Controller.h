//
// Created by Red on 2015/12/29.
//

#ifndef VISITOR1013_2015_CONTROLLER_H
#define VISITOR1013_2015_CONTROLLER_H

class Model;
class Controller {
public:

    void setModel(Model *model) {
        this->model = model;
    }

protected:
    Model *model;
};

#endif //VISITOR1013_2015_CONTROLLER_H
