#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include <vector>

class GraphicsVisitor;

class CompositeGraphics : public Graphics {
public:
    CompositeGraphics(){
        this->father = 0;
    }

    void add(Graphics *g);

    Rectangle getBoundingBox();

    void accept(GraphicsVisitor &v);

    std::vector<Graphics *> getGraphics();

    void setGraphics(std::vector<Graphics *> graphics);

    virtual void move(double x, double y);

private:
    std::vector<Graphics *> g_obj;
public:

    virtual void moveAllChildLocation(QPointF dp);

    virtual void markAllChildStartLocation();

    virtual void backAllChildToStartLocation();

    virtual vector<Painter *> getAllChildPainter();

    virtual void pickAllChild();

    virtual void unpickAllChild();

    virtual Graphics * childContainedPoint(QPointF point);

    virtual Graphics *getChildSelectedGraphics();


};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
