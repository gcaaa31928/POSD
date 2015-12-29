//
// Created by Red on 2015/12/1.
//

#include "SquarePainter.h"


SquarePainter::SquarePainter(int x,int y,int length, Graphics *g) : Painter() {
    _x = x;
    _y = y;
    _width =  length;
    _height = length;
    this->graphics = g;
    _location = QPointF(_x, _y);
    this->setPos(_location);
}

QRectF SquarePainter::boundingRect() const {
    return QRectF(0, 0, _width, _height);
}

void SquarePainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Painter::paint(painter, option, widget);
    painter->drawRect(QRectF(0, 0, _width, _height));
}



