//
// Created by GCA on 2015/10/14.
//

#ifndef VISITOR1013_2015_GRAPHICSVISITOR_H
#define VISITOR1013_2015_GRAPHICSVISITOR_H

#include "SimpleGraphics.h"
#include "CompositeGraphics.h"

class GraphicsVisitor {
public:
    virtual void visitSimpleGraphics(SimpleGraphics *s) = 0;

    virtual void visitCompositeGraphics(CompositeGraphics *c) = 0;

    virtual void clearState() = 0;
};


#endif //VISITOR1013_2015_GRAPHICSVISITOR_H
