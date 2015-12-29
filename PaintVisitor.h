//
// Created by red on 2015/11/19.
//

#ifndef VISITOR1013_2015_PAINTVISITOR_H
#define VISITOR1013_2015_PAINTVISITOR_H

#include "CompositeGraphics.h"
#include "SimpleGraphics.h"
#include "GraphicsVisitor.h"
#include "Circle.h"
#include "GraphicsItemFactory.h"
#include <QGraphicsScene>
#include <algorithm>

class Model;
class PaintVisitor : public GraphicsVisitor {
public:
    PaintVisitor(Model *model): _model(model){ }


    void visitSimpleGraphics(SimpleGraphics *s);

    void visitCompositeGraphics(CompositeGraphics *c);

    void Draw();

    void clearState() {
        items.clear();
    }

    void setScene(QGraphicsScene *scene) {
        PaintVisitor::scene = scene;
    }

private:
    vector<QGraphicsItem *> items;
    QGraphicsScene *scene;
    Model *_model;

};


#endif //VISITOR1013_2015_PAINTVISITOR_H
