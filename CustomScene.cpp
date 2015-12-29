//
// Created by Red on 2015/12/15.
//

#include "CustomScene.h"


void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->setAccepted(true);
    Graphics *graphics;
    if ((graphics = _model->getGraphicsContainedPoint(event->scenePos())) == 0) {
        _model->unselectAllGraphics();
    } else {
        // will selected something
        _model->unselectDeepSelectedGraphics(graphics);
        QGraphicsScene::mousePressEvent(event);
    }
}

void CustomScene::unselectDeepSelectedGraphics(Graphics *exceptGraphics) {
    _model->unselectDeepSelectedGraphics(exceptGraphics);
}

void CustomScene::update(void *pVoid) {

}





//void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//    event->setAccepted(true);
//    if (_model->getSelectedGraphicsContainedPoint(event->scenePos()) == 0) {
//        _pressedLocation = event->scenePos();
//        printf("press\n");
////        this->addItem(_selectionRect);
//        _selecting = true;
////        printf("%.0f %.0f\n", _pressedLocation.x(), _pressedLocation.y());
//    } else {
//        QGraphicsScene::mousePressEvent(event);
//        _selecting = false;
//    }
//}

//void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    event->setAccepted(true);
//    if (_selecting) {
//        printf("move\n");
//        qreal width = event->scenePos().x() - _pressedLocation.x();
//        qreal height = event->scenePos().y() - _pressedLocation.y();
//        QPointF leftUpPoint(_pressedLocation.x(), _pressedLocation.y());
//        if (width < 0) {
//            width = -width;
//            leftUpPoint.setX(event->scenePos().x());
//        }
//        if (height < 0) {
//            height = -height;
//            leftUpPoint.setY(event->scenePos().y());
//        }
//        QRectF qRectF(0, 0, width, height);
//        _selectionRect->setPos(leftUpPoint);
//        _selectionRect->setRect(qRectF);
//    } else {
//        QGraphicsScene::mouseMoveEvent(event);
//    }
//}
//
//void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//    event->setAccepted(true);
//    if (_selecting) {
//        printf("release\n");
//        _model->selectedGraphicsInRect(_selectionRect->rect());
//        QRectF qRectF(0, 0, 0, 0);
//        _selectionRect->setRect(qRectF);
//        this->removeItem(_selectionRect);
//    } else {
//        QGraphicsScene::mouseReleaseEvent(event);
//    }
//}
