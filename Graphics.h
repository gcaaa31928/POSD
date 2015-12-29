#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <algorithm>
#include "Rectangle.h"
#include "Painter.h"
//#include "CompositeGraphics.h"
#include <string>
using namespace std;

class GraphicsVisitor;

class Painter;

class CompositeGraphics;

class Graphics {
public:
    virtual ~Graphics() { }

    virtual Rectangle getBoundingBox() { return Rectangle(0, 0, 0, 0); }

    virtual void add(Graphics *g) { throw std::string("Cannot add child"); }

    virtual void accept(GraphicsVisitor &v) { }

    virtual void move(double x, double y) { }

    virtual void SetPainter(Painter *p) {
        this->painter = p;
    }

    virtual Painter *GetPainter() {
        return this->painter;
    }

    void setParent(CompositeGraphics *father) {
        this->father = father;
    }

    CompositeGraphics *getParent() const {
        return father;
    }

    virtual vector<Painter *> getAllChildPainter() { }

    virtual void moveAllChildLocation(QPointF dp) { }

    virtual void markAllChildStartLocation() { }

    virtual void backAllChildToStartLocation() { }

    virtual void pickAllChild() { }

    virtual void unpickAllChild() { }

    virtual Graphics *childContainedPoint(QPointF point) { }

    virtual Graphics *getChildSelectedGraphics() { }

    virtual int getPrevSibling();

    virtual int getNextSibling();

    virtual int getSiblingIndex();

    virtual bool moveDownLevel();

    virtual bool moveUpLevel();

protected:
    Graphics() { }

    Painter *painter;


protected:
    CompositeGraphics *father;
};

#endif // GRAPHICS_H_INCLUDED
