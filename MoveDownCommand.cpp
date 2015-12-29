//
// Created by red on 2015/12/16.
//

#include "MoveDownCommand.h"


void MoveDownCommand::execute() {
    if (!selectedGraphics->moveDownLevel()){
        failed = true;
    }
    model->redrawGraphics();
}

void MoveDownCommand::unexecute() {
    if (!selectedGraphics->moveUpLevel()){
        failed = true;
    }
    model->redrawGraphics();
}
