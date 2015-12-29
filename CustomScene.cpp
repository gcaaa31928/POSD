//
// Created by Red on 2015/12/15.
//

#include "CustomScene.h"
#include "Model.h"
#include "PaintVisitor.h"


CustomScene::CustomScene(Model *model) : _model(model) {
    _selectionRect = new QGraphicsRectItem(0, 0, 0, 0);
    _selectionRect->setBrush(QBrush(QColor(128, 128, 128, 128)));
    _selectionRect->setPen(QPen(QColor(128, 128, 128, 128)));
    _model->addObserver(this);
}

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

//void CustomScene::unselectDeepSelectedGraphics(Graphics *exceptGraphics) {
//    _model->unselectDeepSelectedGraphics(exceptGraphics);
//}

void CustomScene::update(void *pVoid) {
    Model *model = (Model *) pVoid;

    this->clear();
    vector<Graphics *> graphics_list = model->getGraphicsList();
    CommandManager *commandManager = model->getCommandManager();
    for (int i = graphics_list.size() - 1; i >= 0; i--) {
        PaintVisitor paintVisitor(model);
        paintVisitor.setScene(this);
        graphics_list[i]->accept(paintVisitor);
        paintVisitor.Draw();
    }

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
