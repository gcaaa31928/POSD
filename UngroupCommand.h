//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_UNGROUPCOMMAND_H
#define VISITOR1013_2015_UNGROUPCOMMAND_H

#include "Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>
#include <cstdio>
#include <typeinfo>

class Model;
class UngroupCommand: public Command {
private:

    QGraphicsScene *scene;
    vector<CompositeGraphics *> graphics_list;
    Model *model;
public:
    UngroupCommand(QGraphicsScene *s, Model *m);

    virtual ~UngroupCommand(){};

    void execute();

    void unexecute();
};



#endif //VISITOR1013_2015_UNGROUPCOMMAND_H
