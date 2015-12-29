//
// Created by red on 2015/12/2.
//

#include "UngroupCommand.h"

void UngroupCommand::execute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        graphics_list[i]->unpickAllChild();
        model->removeGraphics(graphics_list[i]);
        vector<Graphics *> child = graphics_list[i]->getGraphics();
        for (int j = 0; j < child.size(); j++) {
            model->addGraphics(child[j]);
        }
//        scene->removeItem(graphics_list[i]->GetPainter());
    }
    model->redrawGraphics();
//    scene->update();
    model->printState();

}

void UngroupCommand::unexecute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        graphics_list[i]->unpickAllChild();
        model->addGraphics(graphics_list[i]);
        vector<Graphics *> child = graphics_list[i]->getGraphics();
        for (int j = 0; j < child.size(); j++) {
            model->removeGraphics(child[j]);
        }
//        scene->addItem(graphics_list[i]->GetPainter());
    }
    model->redrawGraphics();
//    scene->update();
    model->printState();
}
