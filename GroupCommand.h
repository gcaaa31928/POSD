//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_GROUPCOMMAND_H
#define VISITOR1013_2015_GROUPCOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>
#include <cstdio>

class GroupCommand: public Command {
private:
    QGraphicsItem *item;

    QGraphicsScene *scene;
    CompositeGraphics *graphics;
    vector<Graphics *> picked;
    Model *model;
public:
    GroupCommand(QGraphicsScene *s, Model *m, CommandManager *cm):Command() {
        vector<Graphics *> list = m->getGraphicsList();
        CompositeGraphics *cg = new CompositeGraphics();
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->GetPainter()->is_selected()) {
                picked.push_back(list[i]);
                cg->add(list[i]);
            }
        }

        GraphicsItemFactory *factory = new GraphicsItemFactory(cm);
        this->item = factory->createGraphicsItemByCompositeGraphics(cg);
        this->graphics = cg;
        this->model = m;
        this->scene = s;
    }

    virtual ~GroupCommand(){};

    void execute();

    void unexecute();
};


#endif //VISITOR1013_2015_GROUPCOMMAND_H
