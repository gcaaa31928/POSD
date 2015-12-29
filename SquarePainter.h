//
// Created by Red on 2015/12/1.
//

#ifndef VISITOR1013_2015_SQUAREPAINTER_H
#define VISITOR1013_2015_SQUAREPAINTER_H

#include "Painter.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QAction>
#include <QStaticText>
#include "qwidget.h"
#include "Graphics.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <QColor>
#include <QPen>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include "Shape.h"
#include "Square.h"

using namespace std;

class SquarePainter : public Painter {
public:
    SquarePainter(int x,int y,int length, Graphics *g,CommandManager *cm);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    virtual QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView

};


#endif //VISITOR1013_2015_SQUAREPAINTER_H
