//
// Created by red on 2015/12/2.
//

#include "DeleteCommand.h"
#include "Model.h"

DeleteCommand::DeleteCommand(QGraphicsScene *s, Model *m):Command() {
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

void DeleteCommand::execute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        model->removeGraphics(graphics_list[i]);
        vector<Painter *> painters = graphics_list[i]->getAllChildPainter();
        for (int j = 0; j < painters.size(); j++) {
//            scene->removeItem(painters[j]);
        }
    }
}

void DeleteCommand::unexecute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        model->pushGraphics(graphics_list[i]);
        vector<Painter *> painters = graphics_list[i]->getAllChildPainter();
        std::reverse(painters.begin(), painters.end());
        for (int j = 0; j < painters.size(); j++) {
//            scene->addItem(painters[j]);
        }
    }
}

