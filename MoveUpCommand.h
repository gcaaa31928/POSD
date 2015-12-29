//
// Created by red on 2015/12/16.
//

#ifndef VISITOR1013_2015_MOVEUPCOMMAND_H
#define VISITOR1013_2015_MOVEUPCOMMAND_H


#include "Command.h"
#include "Painter.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include "DescriptionVisitor.h"
#include <QGraphicsScene>

class Model;
class MoveUpCommand : public Command {
private:

    Graphics *parentGraphics;
    Graphics *selectedGraphics;
    Painter *painter;
    Model *model;
    int x;
    int y;
public:
    MoveUpCommand(Model *m);

    virtual ~MoveUpCommand() { };

    void execute();

    void unexecute();
};



#endif //VISITOR1013_2015_MOVEUPCOMMAND_H
