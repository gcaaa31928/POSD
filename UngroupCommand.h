//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_UNGROUPCOMMAND_H
#define VISITOR1013_2015_UNGROUPCOMMAND_H

#include "Command.h"
#include "Painter.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>
#include <cstdio>
#include <typeinfo>
class UngroupCommand: public Command {
private:

    QGraphicsScene *scene;
    vector<CompositeGraphics *> graphics_list;
    Model *model;
public:
    UngroupCommand(QGraphicsScene *s, Model *m, CommandManager *cm):Command() {
        int selectedCount = 0;
        vector<Graphics *> list = m->getGraphicsList();
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->GetPainter()->is_selected()) {
                if (typeid(*list[i]) == typeid(CompositeGraphics)) {
                    graphics_list.push_back(dynamic_cast<CompositeGraphics *>(list[i]));
                }
            }
        }
        this->model = m;
        this->scene = s;
    }

    virtual ~UngroupCommand(){};

    void execute();

    void unexecute();
};


#endif //VISITOR1013_2015_UNGROUPCOMMAND_H
