//
// Created by Red on 2015/12/1.
//

#ifndef VISITOR1013_2015_ADDCOMMAND_H
#define VISITOR1013_2015_ADDCOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>

class Model;
class AddCommand : public Command {
private:
    QGraphicsItem *item;
    QGraphicsScene *scene;
    SimpleGraphics *graphics;
    Model *model;

public:
    AddCommand(QGraphicsScene *s, Model *m, SimpleGraphics *g):Command() {
        GraphicsItemFactory *factory = new GraphicsItemFactory(m);
        QPen pen;
        pen.setColor(Qt::green);
        this->item = factory->createGraphicsItemBySimpleGraphics(g, pen);
        this->graphics = g;
        this->model = m;
        this->scene = s;
    }

    virtual ~AddCommand(){};

    void execute();

    void unexecute();
};


#endif //VISITOR1013_2015_ADDCOMMAND_H
