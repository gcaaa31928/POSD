//
// Created by Red on 2015/12/15.
//

#include "CustomScene.h"
#include "Model.h"
#include "Gui.h"
#include "PaintVisitor.h"


CustomScene::CustomScene(Model *model, Gui *gui) : _model(model), _gui(gui) {
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


void CustomScene::update(void *pVoid) {
    Model *model = (Model *) pVoid;
    if (model->isRedrawSign()) {
        this->clear();
        vector<Graphics *> graphics_list = model->getGraphicsList();
        for (int i = graphics_list.size() - 1; i >= 0; i--) {
            PaintVisitor paintVisitor(model);
            paintVisitor.setScene(this);
            graphics_list[i]->accept(paintVisitor);
            paintVisitor.Draw();
        }
    }
    updateButtonState(model);
}


void CustomScene::updateButtonState(Model *model) {
    _gui->undo->setEnabled(model->isUndoEnable());
    _gui->redo->setEnabled(model->isRedoEnable());
    _gui->group->setEnabled(model->isGroupEnable());
    _gui->ungroup->setEnabled(model->isUngroupEnable());
    _gui->deleteAction->setEnabled(model->isDeleteEnable());
    _gui->moveUp->setEnabled(model->isMoveUpEnable());
    _gui->moveDown->setEnabled(model->isMoveDownEnable());
}
