#include <sstream>
#include "Square.h"
#include "Rectangle.h"

Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(x,y,l,l);}
string Square::describe() {
    string s;
    stringstream ss(s);
    ss << "S(" << x << "," << y << "," << l << ")";
    return ss.str();
}

//void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    QPen pen(Qt::blue);
//    painter->setPen(pen);
//    painter->drawRect(x,y,l,l);
//}void Square::move(int x, int y){


