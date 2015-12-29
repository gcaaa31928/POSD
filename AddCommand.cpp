//
// Created by Red on 2015/12/1.
//

#include "AddCommand.h"
#include "Model.h"

void AddCommand::execute() {
    model->addGraphics(graphics);
//    scene->addItem(item);
//    scene->update();
    model->redrawGraphics();
    model->printState();
}

void AddCommand::unexecute() {
    model->removeGraphics(graphics);
//    scene->removeItem(graphics->GetPainter());
//    scene->update();
    model->redrawGraphics();
    model->printState();
}
