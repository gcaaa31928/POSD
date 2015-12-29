#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
    Circle(int center_x, int center_y, int radius);

    int area();

    Rectangle getBoundingBox();

    string describe();

    virtual void move(int x, int y) {
        cx += x;
        cy += y;
    }

    ~Circle() { delete[] d; }

    //int perimeter();



    int cx, cy;
    int r;
    int *d;
};

#endif // CIRCLE_H_INCLUDED
