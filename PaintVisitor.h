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

class PaintVisitor : public GraphicsVisitor {
public:
    PaintVisitor(CommandManager *cm):commandManager(cm) { }

    void visitSimpleGraphics(SimpleGraphics *s) {
        GraphicsItemFactory *factory = new GraphicsItemFactory(commandManager);
        QPen pen;
        pen.setColor(Qt::blue);
        QGraphicsItem *item = factory->createGraphicsItemBySimpleGraphics(s, pen);
        items.push_back(item);

    }

    void visitCompositeGraphics(CompositeGraphics *c) {
        GraphicsItemFactory *factory = new GraphicsItemFactory(commandManager);
        QGraphicsItem *item = factory->createGraphicsItemByCompositeGraphics(c);
        items.push_back(item);
    }

    void Draw() {
        reverse(items.begin(), items.end());
        for (int i = 0; i < items.size(); i++) {
            scene->addItem(items[i]);
            scene->update();
        }
    }

    void clearState() {
        items.clear();
    }

    void setScene(QGraphicsScene *scene) {
        PaintVisitor::scene = scene;
    }

private:
    vector<QGraphicsItem *> items;
    QGraphicsScene *scene;
    CommandManager *commandManager;
};


#endif //VISITOR1013_2015_PAINTVISITOR_H
