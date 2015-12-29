#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"
using namespace std;
class Rectangle : public Shape {
public:
    Rectangle(int ll_x, int ll_y, int length, int width);
    int area();
    string describe();
    Rectangle getBoundingBox();
    int llx() const{return x;}
    int lly() const{return y;}
    int urx() const{return x+l;}
    int ury() const{return y+w;}


    virtual void move(int x, int y) {
        this->x += x;
        this->y += y;
    }


    int x, y;
    int l, w;

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getL() const {
        return l;
    }

    int getW() const {
        return w;
    }
};


#endif // RECTANGLE_H_INCLUDED
