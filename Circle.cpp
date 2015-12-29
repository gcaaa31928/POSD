#include <sstream>
#include "Circle.h"
#include "Rectangle.h"
#include <QColor>

const int PI = 3;

Circle::Circle(int center_x, int center_y, int radius)
        : cx(center_x), cy(center_y), r(radius) { d = new int[10]; }

int Circle::area() { return PI * r * r; }

Rectangle Circle::getBoundingBox() { return Rectangle(cx - r, cy - r, 2 * r, 2 * r); }

string Circle::describe() {
    string s;
    stringstream ss(s);
    ss << "C(" << cx << "," << cy << "," << r << ")";
    return ss.str();
}

//void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    QPen pen(Qt::blue);
//    painter->setPen(pen);
//    painter->drawEllipse(QPointF(cx, cy), r, r);
//}