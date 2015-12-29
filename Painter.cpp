//
// Created by Red on 2015/11/18.
//

#include <cmath>
#include <stdio.h>
#include "Painter.h"
#include "MoveCommand.h"
#include "typeinfo"
#include "DescriptionVisitor.h"
#include "Model.h"

Painter::Painter() : _outterborderColor(Qt::blue),
                     _originColor(Qt::blue),
                     _outterborderPen(),
                     _dragStart(0, 0),
                     _gridSpace(10) {
    _originColor = Qt::black;
    _outterborderColor = Qt::black;
    _filledColor = QColor(110, 161, 250);
    _outterborderPen.setWidth(3);
    _outterborderPen.setStyle(Qt::SolidLine);
    _outterborderPen.setColor(_outterborderColor);
    _selected = false;
    _deepSelected = false;
    this->setAcceptHoverEvents(true);
}

Painter::~Painter() { }


Graphics *Painter::getGraphics() {
    return graphics;
}

void Painter::mouseMoveEvent(QGraphicsSceneDragDropEvent *event) {
    event->setAccepted(false);
}

void Painter::mousePressEvent(QGraphicsSceneDragDropEvent *event) {
    event->setAccepted(false);
}


void Painter::handleMousePicked(QPointF deltaPoint, QPointF pos) {
    cout<<pos.x()<<","<<pos.y()<<endl;
    pos += this->pos();
    if (fabs(deltaPoint.x()) + fabs(deltaPoint.y()) <= 4) {
        if (_selected) {
            cout<<"fuck you"<<endl;
            DescriptionVisitor dv;
            Graphics *graphics = this->getGraphics()->childContainedPoint(pos);
//            cout << graphics << endl;
            // did not chose something or chosen by itself
            if (graphics == 0 || graphics == this->getGraphics()) {
                this->_deepSelected = false;
                this->getGraphics()->unpickAllChild();
                this->set_selected(true);
                return;
            }
            this->getGraphics()->unpickAllChild();
            for (Graphics *parent = graphics->getParent(); parent != 0; parent = parent->getParent()) {
                cout << parent << endl;
                parent->GetPainter()->set_deepSelected(true);
            }
            this->_deepSelected = true;
            graphics->GetPainter()->set_selected(true);
            graphics->accept(dv);
//            cout<<dv.getDescription()<<endl;
        }
        _selected = true;
        if (_selected) {
            cout<<"fuck you2"<<endl;
            _outterborderColor = Qt::red;
            this->update(0, 0, _width, _height);

        }
    }
}

void Painter::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    event->setAccepted(true);// tell the base class we are handling this event

    // force my box to snap to grid, just truncate the pixel number and
    // snap to the next lowest grid value
    QPointF dp = QPointF(0, 0);
    if (_selected) {
        _location.setX((static_cast<int>(_location.x()) / _gridSpace) * _gridSpace);
        _location.setY((static_cast<int>(_location.y()) / _gridSpace) * _gridSpace);
        _endLocation = _location;
        dp = (_endLocation - _startLocation);
        this->graphics->backAllChildToStartLocation();
        model->moveGraphicsToPoint(this->graphics, this, dp);
        this->setPos(_location);
    }
    this->handleMousePicked(dp, event->pos());
}

void Painter::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // allow the user to drag the box, capture the starting position on mouse-down
    event->setAccepted(true);
    if (_selected) {

        markStartLocation();
        _dragStart = event->pos();
        _dragDis = QPointF(0, 0);
        this->graphics->markAllChildStartLocation();
    }
}

void Painter::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    // user have moved the mouse, move the location of the box
    if (_selected) {
        QPointF newPos = event->pos();
        QPointF dp = (newPos - _dragStart);
        _dragDis += dp;
        this->graphics->moveAllChildLocation(dp);
    }
}

void Painter::hoverLeaveEvent(QGraphicsSceneHoverEvent *) {
    // return the box color to black when the mouse is no longer hovering
    this->update(0, 0, _width, _height);
}

void Painter::hoverEnterEvent(QGraphicsSceneHoverEvent *) {
    // draw the box in red if the mouse is hovering over it
    this->update(0, 0, _width, _height);
}

// boundingRect must be re-implemented from the base class to provide the scene with
// size info about this custom GraphicsItem

QRectF Painter::boundingRect() const {
    return QRectF(0, 0, _width, _height);
}


void Painter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    _outterborderPen.setColor(_outterborderColor);

    painter->setBrush(_filledColor);
    painter->setPen(_outterborderPen);
}
