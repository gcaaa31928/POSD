//
// Created by red on 2015/11/19.
//

#include "PaintVisitor.h"

#include "Model.h"

void PaintVisitor::visitSimpleGraphics(SimpleGraphics *s){
    GraphicsItemFactory *factory = new GraphicsItemFactory(_model);
    QPen pen;
    pen.setColor(Qt::blue);
    QGraphicsItem *item = factory->createGraphicsItemBySimpleGraphics(s, pen);
    items.push_back(item);

}

void PaintVisitor::visitCompositeGraphics(CompositeGraphics *c) {
    GraphicsItemFactory *factory = new GraphicsItemFactory(_model);
    QGraphicsItem *item = factory->createGraphicsItemByCompositeGraphics(c);
    items.push_back(item);
}


void PaintVisitor::Draw() {
    reverse(items.begin(), items.end());
    for (int i = 0; i < items.size(); i++) {
        scene->addItem(items[i]);
        scene->update();
    }
}
