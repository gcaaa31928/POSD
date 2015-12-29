#include <sstream>
#include "Rectangle.h"

Rectangle::Rectangle(int ll_x, int ll_y, int length, int width)
        : x(ll_x), y(ll_y), l(length), w(width) { }

int Rectangle::area() { return l * w; }

Rectangle Rectangle::getBoundingBox() { return Rectangle(x, y, l, w); }

string Rectangle::describe() {
    string s;
    stringstream ss(s);
    ss << "R(" << x << "," << y << "," << l << "," << w << ")";
    return ss.str();
}

//void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    QPen pen(Qt::blue);
//    painter->setPen(pen);
//    painter->drawRect(x,y,w,l);
//}void Rectangle::move(int x, int y){


