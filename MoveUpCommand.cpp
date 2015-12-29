//
// Created by red on 2015/12/16.
//

#include "MoveUpCommand.h"


void MoveUpCommand::execute() {
    if (!selectedGraphics->moveUpLevel()){
        failed = true;
    }
    model->redrawGraphics();
}

void MoveUpCommand::unexecute() {
    if (!selectedGraphics->moveDownLevel()){
        failed = true;
    }
    model->redrawGraphics();
}
