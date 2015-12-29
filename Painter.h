//
// Created by Red on 2015/11/18.
//

#ifndef VISITOR1013_2015_PAINTER_H
#define VISITOR1013_2015_PAINTER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QAction>
#include <QStaticText>
#include "qwidget.h"
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
#include "Graphics.h"
#include "CommandManager.h"
#include "Controller.h"
#include <cstdio>

using namespace std;

class Graphics;

class Painter : public QGraphicsItem, public Controller {
public:
    Painter(CommandManager *cm);

    virtual ~Painter();


    void setGridSpace(int space) { };

    virtual Graphics *getGraphics();

    virtual void SetFilledColor(QColor color) {
        this->_filledColor = color;
    }

    virtual void SetOutterColor(QColor color) {
        this->_outterborderColor = color;
        this->_originColor = color;
    }

    virtual bool containsPoint(QPointF point) {
        QPointF leftUpCorner = this->pos();
        QRectF rect(leftUpCorner.x(), leftUpCorner.y(), _width, _height);
        return rect.contains(point);
    }

    virtual bool containsRect(QRectF rect) {
        QRectF painterRect(this->pos().x(), this->pos().y(), _width, _height);
        return rect.intersects(painterRect);
    }

protected:

    virtual QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    virtual void hoverEnterEvent(
            QGraphicsSceneHoverEvent *event); ///< must be re-implemented to handle mouse hover enter events
    virtual void hoverLeaveEvent(
            QGraphicsSceneHoverEvent *event); ///< must be re-implemented to handle mouse hover leave events
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    ///< re-implemented to capture events
    virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);

    ///< re-implemented to capture events
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

    ///< re-implemented to capture events
    virtual void mousePressEvent(QGraphicsSceneDragDropEvent *event);

    ///< re-implemented to capture events
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void handleMousePicked(QPointF deltaPoint, QPointF pos);

    ///< re-implemented to capture events
    QColor _originColor;
    QColor _outterborderColor; ///< the hover event handlers will toggle this between red and black
    QColor _filledColor;
    QPen _outterborderPen; ///< the pen is used to paint the red/black border
    QPointF _location;
    QPointF _dragStart;
    QPointF _dragDis;
    QPointF _startLocation;
    QPointF _endLocation;
    int _gridSpace;
    qreal _x;
    qreal _y;
    qreal _width;
    qreal _height;
    Graphics *graphics;
    CommandManager *commandManager;


protected:
    bool _selected;
    bool _deepSelected;
public:


    void set_selected(bool _selected) {
        if (_selected) {
            _outterborderColor = Qt::red;
        } else {
            _deepSelected = false;
            _outterborderColor = _originColor;
        }
        Painter::_selected = _selected;
        this->update(0, 0, _width, _height);
    }


    void set_deepSelected(bool _deepSelected) {
        if (_deepSelected) {
            _outterborderColor = Qt::red;
        }
        Painter::_deepSelected = _deepSelected;
        this->update(0, 0, _width, _height);
    }

    const QPointF &get_location() const {
        return _location;
    }

    bool is_selected() const {
        return _selected;
    }

    void set_location(const QPointF &_location) {
        Painter::_location = _location;
    }

    void backToStartLocation() {
        _location = _startLocation;
    }

    void markStartLocation() {
        _startLocation = _location;
    }


    bool is_deepSelected() const {
        return _deepSelected;
    }
};

#endif //VISITOR1013_2015_PAINTER_H
