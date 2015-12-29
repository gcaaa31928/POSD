#ifndef SIMPLEGRAPHICS_H_INCLUDED
#define SIMPLEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include "Shape.h"

class GraphicsVisitor;

class SimpleGraphics : public Graphics {
public:
    SimpleGraphics (Shape *shape_inst):s(shape_inst) {
        this->father = 0;
    }
    Rectangle getBoundingBox() {return s->getBoundingBox();}
    Shape * getShape() {return s;}
    void accept(GraphicsVisitor &v) ;

    virtual void move(double x, double y);

private:
    Shape * s;
public:
    virtual void moveAllChildLocation(QPointF dp);

    virtual void markAllChildStartLocation();

    virtual void backAllChildToStartLocation();

    virtual vector<Painter *> getAllChildPainter();

    virtual void pickAllChild();

    virtual void unpickAllChild();

    virtual Graphics *childContainedPoint(QPointF point);

    virtual Graphics * getChildSelectedGraphics();

};


#endif // SIMPLEGRAPHICS_H_INCLUDED
