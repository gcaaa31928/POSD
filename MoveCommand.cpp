//
// Created by Red on 2015/12/2.
//

#include "MoveCommand.h"

void MoveCommand::execute() {

    graphics->move(x, y);


}

void MoveCommand::unexecute() {
    graphics->move(-x, -y);
}

