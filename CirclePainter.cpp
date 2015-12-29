//
// Created by Red on 2015/12/1.
//

#include "CirclePainter.h"


CirclePainter::CirclePainter(int x, int y, int r, Graphics *g, CommandManager *cm) : Painter(cm) {
    _x = x - r;
    _y = y - r;
    _width = 2 * r;
    _height = 2 * r;
    this->graphics = g;

    _location = QPointF(_x, _y);
    this->setPos(_location);
}

QRectF CirclePainter::boundingRect() const {
    return QRectF(0, 0, _width, _height);
}

void CirclePainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Painter::paint(painter, option, widget);
    painter->drawEllipse(QRectF(0, 0, _width, _height));
}
