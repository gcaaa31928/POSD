#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <string>
#include <QtWidgets/qgraphicsitem.h>
using namespace std;
class Rectangle;
class Shape{
public:
    virtual ~Shape(){}
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual string describe() = 0;
    virtual void move(int x,int y) = 0;
};


#endif // SHAPE_H_INCLUDED
