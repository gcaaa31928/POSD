//
// Created by red on 2015/12/16.
//

#include "MoveDownCommand.h"
#include "Model.h"

MoveDownCommand::MoveDownCommand(Model *m):Command() {
    model = m;
    parentGraphics = m->getDeepGraphics();
    if (parentGraphics == 0) {
        failed = true;
        return;
    }
    selectedGraphics = parentGraphics->getChildSelectedGraphics();
}

void MoveDownCommand::execute() {
    if (!selectedGraphics->moveDownLevel()){
        failed = true;
    }
}

void MoveDownCommand::unexecute() {
    if (!selectedGraphics->moveUpLevel()){
        failed = true;
    }
}
