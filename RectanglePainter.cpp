//
// Created by Red on 2015/12/1.
//

#include "RectanglePainter.h"

RectanglePainter::RectanglePainter(int x, int y, int width, int height, Graphics *g, CommandManager *cm) : Painter(cm) {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    this->graphics = g;

    _location = QPointF(_x, _y);
    this->setPos(_location);
}

QRectF RectanglePainter::boundingRect() const {
    return QRectF(0, 0, _width, _height);
}

void RectanglePainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Painter::paint(painter, option, widget);
    painter->drawRect(QRectF(0, 0, _width, _height));
}