//
// Created by red on 2015/12/16.
//

#ifndef VISITOR1013_2015_MOVEDOWNCOMMAND_H
#define VISITOR1013_2015_MOVEDOWNCOMMAND_H



#include "Command.h"
#include "Painter.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "GraphicsItemFactory.h"
#include "DescriptionVisitor.h"
#include <QGraphicsScene>

class MoveDownCommand : public Command {
private:

    Graphics *parentGraphics;
    Graphics *selectedGraphics;
    Painter *painter;
    Model *model;
    int x;
    int y;
public:
    MoveDownCommand(Model *m):Command() {
        model = m;
        parentGraphics = m->getDeepGraphics();
        if (parentGraphics == 0) {
            failed = true;
            return;
        }
        selectedGraphics = parentGraphics->getChildSelectedGraphics();
    }

    virtual ~MoveDownCommand() { };

    void execute();

    void unexecute();
};



#endif //VISITOR1013_2015_MOVEDOWNCOMMAND_H
