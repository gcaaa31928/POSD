//
// Created by Red on 2015/12/15.
//

#ifndef VISITOR1013_2015_CUSTOMSCENE_H
#define VISITOR1013_2015_CUSTOMSCENE_H


#include <QtWidgets/qgraphicsscene.h>
#include "Views.h"

class Model;
class Gui;
class CustomScene : public QGraphicsScene, public Views {

public:
    CustomScene(Model *model, Gui *gui);

    void updateButtonState(Model *);
    virtual void update(void *pVoid);
protected:

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
private:
    Model *_model;
    QPointF _pressedLocation;
    QGraphicsRectItem *_selectionRect;
    bool _selecting;
    Gui *_gui;
};

#endif //VISITOR1013_2015_CUSTOMSCENE_H
