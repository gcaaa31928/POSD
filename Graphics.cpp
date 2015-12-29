//
// Created by red on 2015/12/16.
//
#include "Graphics.h"
#include "CompositeGraphics.h"
#include "DescriptionVisitor.h"

bool Graphics::moveUpLevel() {
    CompositeGraphics *cg = this->getParent();
    DescriptionVisitor dv;
    cg->accept(dv);
    cout<<"here"<<endl;
    cout<<dv.getDescription()<<endl;
    vector<Graphics *> sibling = cg->getGraphics();
    int prevIndex = -1;
    int index = 0;
    for (int i = 0; i < sibling.size(); i++) {
        if (this == sibling[i]) {
            prevIndex = i - 1;
            index = i;
            break;
        }
    }
    if (prevIndex < 0) return false;
    swap(sibling[prevIndex], sibling[index]);
    cg->setGraphics(sibling);
    return true;
}


bool Graphics::moveDownLevel() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int nextIndex = -1;
    int index = 0;
    for (int i = 0; i < sibling.size(); i++) {
        if (this == sibling[i]) {
            nextIndex = i + 1;
            index = i;
            break;
        }
    }
    if (nextIndex >= sibling.size()) return false;
    swap(sibling[nextIndex], sibling[index]);
    cg->setGraphics(sibling);
    return true;
}
