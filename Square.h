#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "Shape.h"
#include <QtWidgets/qgraphicsitem.h>
#include <QPen>
#include <QPainter>

using namespace std;


class Square : public Shape {
public:
    Square(int ll_x, int ll_y, int length);

    int area();

    Rectangle getBoundingBox();

    string describe();
    //int perimeter();




    virtual void move(int x, int y) {
        this->x += x;
        this->y += y;
    };


    int x, y;
    int l;

};


#endif // SQUARE_H_INCLUDED
