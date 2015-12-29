//
// Created by red on 2015/11/19.
//

#ifndef VISITOR1013_2015_GRAPHICSITEMFACTORY_H
#define VISITOR1013_2015_GRAPHICSITEMFACTORY_H

#include <QGraphicsItem>
#include <QtGui/qpen.h>
#include "Shape.h"
#include "SimpleGraphics.h"
#include "CommandManager.h"
#include "CompositeGraphics.h"

class GraphicsItemFactory {
public:

    GraphicsItemFactory(CommandManager *cm):commandManager(cm){

    }
    QGraphicsItem*createGraphicsItemBySimpleGraphics(SimpleGraphics *g, QPen pen);
    QGraphicsItem*createGraphicsItemByCompositeGraphics(CompositeGraphics *g);
private:
    CommandManager *commandManager;
};


#endif //VISITOR1013_2015_GRAPHICSITEMFACTORY_H
