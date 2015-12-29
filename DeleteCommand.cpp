//
// Created by red on 2015/12/2.
//

#include "DeleteCommand.h"
void DeleteCommand::execute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        model->removeGraphics(graphics_list[i]);
        vector<Painter *> painters = graphics_list[i]->getAllChildPainter();
        for (int j = 0; j < painters.size(); j++) {
//            scene->removeItem(painters[j]);
        }
    }
    model->redrawGraphics();
//    scene->update();
    model->printState();

}

void DeleteCommand::unexecute() {
    for (int i = 0; i < graphics_list.size(); i++) {
        model->addGraphics(graphics_list[i]);
        vector<Painter *> painters = graphics_list[i]->getAllChildPainter();
        std::reverse(painters.begin(), painters.end());
        for (int j = 0; j < painters.size(); j++) {
//            scene->addItem(painters[j]);
        }
    }
    model->redrawGraphics();
//    scene->update();
    model->printState();
}
