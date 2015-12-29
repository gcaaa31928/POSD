//
// Created by Red on 2015/12/2.
//

#include "Model.h"
#include "Gui.h"
#include "DescriptionVisitor.h"
#include "PaintVisitor.h"

void Model::pushGraphics(Graphics *graphics) {
    graphics_list.insert(graphics_list.begin(), graphics);
//    graphics_list.push_back(graphics);
}


void Model::addMultipleGraphics(vector<Graphics *> gs) {
    for (int i = 0; i < gs.size(); i++) {
        graphics_list.push_back(gs[i]);
    }
}

void Model::removeLastGraphics() {
    graphics_list.pop_back();
}

void Model::removeGraphics(Graphics *graphics) {
    int clearIndex = -1;
    for (int i = 0; i < graphics_list.size(); i++) {
        if (graphics_list[i] == graphics) {
            clearIndex = i;
        }
    }
    if (clearIndex != -1) {
        graphics_list.erase(graphics_list.begin() + clearIndex);
    }
}

void Model::printState() {
    DescriptionVisitor dv;
    vector<Graphics *> graphics = this->getGraphicsList();
    cout << "--------------------" << endl;
    for (int i = 0; i < graphics.size(); i++) {
        graphics[i]->accept(dv);
        cout << dv.getDescription() << endl;
        dv.clearState();
    }
    cout << "--------------------" << endl;
}


Graphics *Model::getSelectedGraphicsContainedPoint(QPointF point) {
    for (int i = 0; i < graphics_list.size(); i++) {
        if (graphics_list[i]->GetPainter()->containsPoint(point) && graphics_list[i]->GetPainter()->is_selected()) {
            return graphics_list[i];
        }
    }
    return 0;
}


Graphics *Model::getGraphicsContainedPoint(QPointF point) {
    for (int i = 0; i < graphics_list.size(); i++) {
        if (graphics_list[i]->GetPainter()->containsPoint(point)) {
            return graphics_list[i];
        }
    }
    return 0;
}

void Model::selectedGraphicsInRect(QRectF qRectF) {
    for (int i = 0; i < graphics_list.size(); i++) {
        if (graphics_list[i]->GetPainter()->containsRect(qRectF)) {
            graphics_list[i]->GetPainter()->set_selected(true);
        }
    }
}

void Model::unselectAllGraphics() {
    for (int i = 0; i < graphics_list.size(); i++) {
        graphics_list[i]->unpickAllChild();
    }
    _redrawSign = false;
}

void Model::unselectDeepSelectedGraphics(Graphics *exceptGraphics) {
    for (int i = 0; i < graphics_list.size(); i++) {
        if (exceptGraphics == graphics_list[i])continue;
        if (graphics_list[i]->GetPainter()->is_deepSelected()) {
            graphics_list[i]->unpickAllChild();
        }
    }
}


void Model::clearSceneItems() {

}

void Model::redrawGraphics() {
    scene->clear();
    for (int i = graphics_list.size() - 1; i >= 0; i--) {
        PaintVisitor paintVisitor(this);
        paintVisitor.setScene(scene);
        graphics_list[i]->accept(paintVisitor);
        paintVisitor.Draw();
    }
}


Graphics *Model::getDeepGraphics() {
    for (int i = 0; i < graphics_list.size(); i++) {
        if (graphics_list[i]->GetPainter()->is_deepSelected()) {
            return graphics_list[i];
        }
    }
    return 0;
}
