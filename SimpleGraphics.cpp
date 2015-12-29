#include "SimpleGraphics.h"
#include "GraphicsVisitor.h"

void SimpleGraphics::accept(GraphicsVisitor &v) {
    v.visitSimpleGraphics(this);
}

void SimpleGraphics::move(double x, double y) {
    this->getShape()->move(x, y);
    QPointF currentPos = painter->get_location();
    painter->set_location(currentPos + QPointF(x, y));
    painter->setPos(painter->get_location());
}

void SimpleGraphics::moveAllChildLocation(QPointF dp) {
    QPointF currentPos = painter->get_location();
    painter->set_location(currentPos + dp);
    painter->setPos(painter->get_location());
}


void SimpleGraphics::markAllChildStartLocation() {
    painter->markStartLocation();
}


void SimpleGraphics::backAllChildToStartLocation() {
    painter->backToStartLocation();
}

vector<Painter *> SimpleGraphics::getAllChildPainter() {
    vector<Painter *> p;
    p.push_back(painter);
    return p;
}

void SimpleGraphics::pickAllChild() {
    painter->set_selected(true);
}

void SimpleGraphics::unpickAllChild() {
    painter->set_selected(false);
}

Graphics *SimpleGraphics::childContainedPoint(QPointF point) {
    if (this->GetPainter()->containsPoint(point)) {
        return this;
    }
    return 0;
}

Graphics * SimpleGraphics::getChildSelectedGraphics() {
    if (this->GetPainter()->is_selected()){
        return this;
    }
    return 0;
}

