#include "CompositeGraphics.h"
#include <algorithm>
#include "GraphicsVisitor.h"



void CompositeGraphics::add(Graphics *g) {
    g_obj.push_back(g);
    g->setParent(this);
}

Rectangle CompositeGraphics::getBoundingBox() {
    if (g_obj.size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i = g_obj.begin(); i != g_obj.end(); ++i) {
        minx.push_back((*i)->getBoundingBox().llx());
        miny.push_back((*i)->getBoundingBox().lly());
        maxx.push_back((*i)->getBoundingBox().urx());
        maxy.push_back((*i)->getBoundingBox().ury());
    }
    int llx = *min_element(minx.begin(), minx.end());
    int lly = *min_element(miny.begin(), miny.end());
    int urx = *max_element(maxx.begin(), maxx.end());
    int ury = *max_element(maxy.begin(), maxy.end());

    return Rectangle(llx, lly, urx - llx, ury - lly);
}

void CompositeGraphics::accept(GraphicsVisitor &v) {
    v.visitCompositeGraphics(this);
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->accept(v);
    }
}

std::vector<Graphics *> CompositeGraphics::getGraphics() {
    return g_obj;
}


void CompositeGraphics::setGraphics(std::vector<Graphics *> graphics) {
    g_obj = graphics;
}

void CompositeGraphics::move(double x, double y) {
    QPointF currentPos = painter->get_location();
    painter->set_location(currentPos + QPointF(x, y));
    painter->setPos(painter->get_location());
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->move(x, y);
    }

}


void CompositeGraphics::moveAllChildLocation(QPointF dp) {
    QPointF currentPos = painter->get_location();
    painter->set_location(currentPos + dp);
    painter->setPos(painter->get_location());
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->moveAllChildLocation(dp);
    }
}

void CompositeGraphics::markAllChildStartLocation() {
    painter->markStartLocation();
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->markAllChildStartLocation();
    }
}


void CompositeGraphics::backAllChildToStartLocation() {
    painter->backToStartLocation();
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->backAllChildToStartLocation();
    }
}

vector<Painter *> CompositeGraphics::getAllChildPainter() {
    vector<Painter *> painters;
    painters.push_back(painter);
    for (int i = 0; i < g_obj.size(); i++) {
        vector<Painter *> child = g_obj[i]->getAllChildPainter();
        for (int j = 0; j < child.size(); j++) {
            painters.push_back(child[j]);
        }
    }
    return painters;
}


void CompositeGraphics::pickAllChild() {
    painter->set_selected(true);
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->pickAllChild();
    }
}

void CompositeGraphics::unpickAllChild() {
    painter->set_selected(false);
    for (int i = 0; i < g_obj.size(); i++) {
        g_obj[i]->unpickAllChild();
    }
}


Graphics *CompositeGraphics::childContainedPoint(QPointF point) {
    for (int i = 0; i < g_obj.size(); i++) {
        Graphics *result;
        if ((result = g_obj[i]->childContainedPoint(point)) != 0) {
            return result;
        }
    }
    if (this->GetPainter()->containsPoint(point)) {
        return this;
    }
    return 0;
}

Graphics *CompositeGraphics::getChildSelectedGraphics() {
    for (int i = 0; i < g_obj.size(); i++) {
        Graphics *result;
        if ((result = g_obj[i]->getChildSelectedGraphics()) != 0) {
            return result;
        }
    }
    if (this->GetPainter()->is_selected() && !this->GetPainter()->is_deepSelected()) {
        return this;
    }
    return 0;
}
