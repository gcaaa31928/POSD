//
// Created by red on 2015/12/2.
//

#include "UngroupCommand.h"
#include "Model.h"

UngroupCommand::UngroupCommand(QGraphicsScene *s, Model *m):Command() {
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

void UngroupCommand::execute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        graphics_list[i]->unpickAllChild();
        model->removeGraphics(graphics_list[i]);
        vector<Graphics *> child = graphics_list[i]->getGraphics();
        for (int j = 0; j < child.size(); j++) {
            model->addGraphics(child[j]);
        }
    }
}

void UngroupCommand::unexecute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        graphics_list[i]->unpickAllChild();
        model->addGraphics(graphics_list[i]);
        vector<Graphics *> child = graphics_list[i]->getGraphics();
        for (int j = 0; j < child.size(); j++) {
            model->removeGraphics(child[j]);
        }
    }
}
