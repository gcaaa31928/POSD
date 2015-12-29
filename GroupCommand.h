//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_GROUPCOMMAND_H
#define VISITOR1013_2015_GROUPCOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>
#include <cstdio>

class Model;
class GroupCommand: public Command {
private:
    QGraphicsItem *item;

    QGraphicsScene *scene;
    CompositeGraphics *graphics;
    vector<Graphics *> picked;
    Model *model;
public:
    GroupCommand(QGraphicsScene *s, Model *m);

    virtual ~GroupCommand(){};

    void execute();

    void unexecute();
};


#endif //VISITOR1013_2015_GROUPCOMMAND_H
