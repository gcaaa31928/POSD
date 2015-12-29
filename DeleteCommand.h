//
// Created by red on 2015/12/2.
//

#ifndef VISITOR1013_2015_DELETECOMMAND_H
#define VISITOR1013_2015_DELETECOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>

class DeleteCommand : public Command {
private:
    QGraphicsItem *item;

    QGraphicsScene *scene;
    vector<Graphics *> graphics_list;
    Model *model;

public:
    DeleteCommand(QGraphicsScene *s, Model *m ,CommandManager *cm):Command() {
        int selectedCount = 0;
        vector<Graphics *> list = m->getGraphicsList();
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->GetPainter()->is_selected()) {
                graphics_list.push_back(list[i]);
            }
        }
        this->model = m;
        this->scene = s;
    }

    virtual ~DeleteCommand(){};

    void execute();

    void unexecute();
};



#endif //VISITOR1013_2015_DELETECOMMAND_H
