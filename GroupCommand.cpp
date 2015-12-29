//
// Created by red on 2015/12/2.
//

#include "GroupCommand.h"
#include "CompositeGraphics.h"
#include "DescriptionVisitor.h"

void GroupCommand::execute() {
    for (int i=0;i<picked.size();i++) {
        model->removeGraphics(picked[i]);
        picked[i]->unpickAllChild();
    }
    graphics->unpickAllChild();
    model->addGraphics(graphics);
    model->redrawGraphics();
    model->printState();
}

void GroupCommand::unexecute() {
    for (int i=0;i<picked.size();i++) {
        model->addGraphics(picked[i]);
    }
    model->removeGraphics(graphics);
    model->redrawGraphics();
    model->printState();
}
