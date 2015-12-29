//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_DELETECOMMAND_H
#define VISITOR1013_2015_DELETECOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>

class Model;
class DeleteCommand : public Command {
private:
    QGraphicsItem *item;

    QGraphicsScene *scene;
    vector<Graphics *> graphics_list;
    Model *model;

public:
    DeleteCommand(QGraphicsScene *s, Model *m);

    virtual ~DeleteCommand(){};

    void execute();

    void unexecute();
};




#endif //VISITOR1013_2015_DELETECOMMAND_H
