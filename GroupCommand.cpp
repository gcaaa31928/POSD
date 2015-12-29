//
// Created by red on 2015/12/2.
//

#include "GroupCommand.h"
#include "CompositeGraphics.h"
#include "DescriptionVisitor.h"
#include "Model.h"

GroupCommand::GroupCommand(QGraphicsScene *s, Model *m) :Command() {
    vector<Graphics *> list = m->getGraphicsList();
    CompositeGraphics *cg = new CompositeGraphics();
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->GetPainter()->is_selected()) {
            picked.push_back(list[i]);
            cg->add(list[i]);
        }
    }

    GraphicsItemFactory *factory = new GraphicsItemFactory(m);
    this->item = factory->createGraphicsItemByCompositeGraphics(cg);
    this->graphics = cg;
    this->model = m;
    this->scene = s;
}

void GroupCommand::execute() {
    for (int i=0;i<picked.size();i++) {
        model->removeGraphics(picked[i]);
        picked[i]->unpickAllChild();
    }
    graphics->unpickAllChild();
    model->pushGraphics(graphics);
    model->redrawGraphics();
    model->printState();
}

void GroupCommand::unexecute() {
    for (int i=0;i<picked.size();i++) {
        model->pushGraphics(picked[i]);
    }
    model->removeGraphics(graphics);
    model->redrawGraphics();
    model->printState();
}
