//
// Created by red on 2015/12/16.
//

#include "MoveUpCommand.h"
#include "Model.h"

MoveUpCommand::MoveUpCommand(Model *m) : Command() {
    model = m;
    parentGraphics = m->getDeepGraphics();
    if (parentGraphics == 0) {
        failed = true;
        return;
    }
    selectedGraphics = parentGraphics->getChildSelectedGraphics();
}

void MoveUpCommand::execute() {
    if (!selectedGraphics->moveUpLevel()) {
        failed = true;
    }
}

void MoveUpCommand::unexecute() {
    if (!selectedGraphics->moveDownLevel()) {
        failed = true;
    }
}
