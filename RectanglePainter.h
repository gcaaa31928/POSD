//
// Created by Red on 2015/12/1.
//

#ifndef VISITOR1013_2015_RECTANGLEPAINTER_H
#define VISITOR1013_2015_RECTANGLEPAINTER_H

#include "Painter.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QAction>
#include <QStaticText>
#include "qwidget.h"
#include "Rectangle.h"
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

class RectanglePainter : public Painter {
public:
    RectanglePainter(int x,int y,int width, int height, Graphics *g);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    virtual QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView
};


#endif //VISITOR1013_2015_RECTANGLEPAINTER_H
