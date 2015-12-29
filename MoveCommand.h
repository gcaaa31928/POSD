//
// Created by Red on 2015/12/2.
//

#ifndef VISITOR1013_2015_MOVECOMMAND_H
#define VISITOR1013_2015_MOVECOMMAND_H


#include"Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>

class MoveCommand : public Command {
private:

    Graphics *graphics;
    Painter *painter;
    int x;
    int y;
public:
    MoveCommand(Graphics *g, Painter *p, int x, int y):Command() {
        if (x == 0 && y == 0){
            failed = true;
        }
        graphics = g;
        painter = p;
        this->x = x;
        this->y = y;
    }

    virtual ~MoveCommand() { };

    void execute();

    void unexecute();
};

#endif //VISITOR1013_2015_MOVECOMMAND_H
