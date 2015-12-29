//
// Created by red on 2015/11/19.
//

#include <sstream>
#include <stdio.h>
#include <QGraphicsEllipseItem>
#include "GraphicsItemFactory.h"
#include "SimpleGraphics.h"
#include "Square.h"
#include "CirclePainter.h"
#include "SquarePainter.h"
#include "RectanglePainter.h"
#include <QColor>
#include <QPen>
#include <QPainter>

using namespace std;

QGraphicsItem *GraphicsItemFactory::createGraphicsItemBySimpleGraphics(SimpleGraphics *g, QPen pen) {

    string substring = g->getShape()->describe();
    stringstream ss(substring);
    int loc = substring.find("C");
    if (loc != string::npos) {
        int x, y, r;
        sscanf(substring.c_str(), "C(%d,%d,%d)", &x, &y, &r);
        Painter *p = new CirclePainter(x, y, r, g, commandManager);
        g->SetPainter(p);
        return p;
    }
    loc = substring.find("S");
    if (loc != string::npos) {
        int x, y, l;
        sscanf(substring.c_str(), "S(%d,%d,%d)", &x, &y, &l);
        Painter *p = new SquarePainter(x, y, l, g, commandManager);
        g->SetPainter(p);
        return p;
    }
    loc = substring.find("R");
    if (loc != string::npos) {
        int x, y, l, w;
        sscanf(substring.c_str(), "R(%d,%d,%d,%d)", &x, &y, &l, &w);
        Painter *p = new RectanglePainter(x, y, l, w, g, commandManager);
        g->SetPainter(p);
        return p;
    }
}

QGraphicsItem *GraphicsItemFactory::createGraphicsItemByCompositeGraphics(CompositeGraphics *g) {
    Rectangle rectangle = g->getBoundingBox();
    Painter *p = new RectanglePainter(rectangle.getX(),
                                      rectangle.getY(),
                                      rectangle.getL(),
                                      rectangle.getW(), g, commandManager);
    p->SetFilledColor(Qt::transparent);
    p->SetOutterColor(Qt::green);
    g->SetPainter(p);
    return p;
}
