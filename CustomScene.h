//
// Created by Red on 2015/12/15.
//

#ifndef VISITOR1013_2015_CUSTOMSCENE_H
#define VISITOR1013_2015_CUSTOMSCENE_H


#include <QtWidgets/qgraphicsscene.h>
#include "Model.h"
#include "Views.h"

class Model;
class CustomScene : public Views, public QGraphicsScene {

public:
    CustomScene(Model *model) : _model(model) {
        _selectionRect = new QGraphicsRectItem(0, 0, 0,0);
        _selectionRect->setBrush(QBrush(QColor(128, 128, 128, 128)));
        _selectionRect->setPen(QPen(QColor(128, 128, 128, 128)));

    }

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
    void unselectDeepSelectedGraphics(Graphics *graphics);

private:
    Model *_model;
    QPointF _pressedLocation;
    QGraphicsRectItem *_selectionRect;
    bool _selecting;
public:
    virtual void update(void *pVoid);
};


#endif //VISITOR1013_2015_CUSTOMSCENE_H
