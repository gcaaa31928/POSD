//
// Created by red on 2015/12/16.
//
#include "Graphics.h"
#include "CompositeGraphics.h"
#include "DescriptionVisitor.h"


int Graphics::getPrevSibling() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int prevIndex = -1;
    for (int i = 0; i < sibling.size(); i++) {
        if (this == sibling[i]) {
            prevIndex = i - 1;
            break;
        }
    }
    return prevIndex;
}

int Graphics::getNextSibling() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int nextIndex = sibling.size();
    for (int i = 0; i < sibling.size(); i++) {
        if (this == sibling[i]) {
            nextIndex = i + 1;
            break;
        }
    }
    return nextIndex;
}


int Graphics::getSiblingIndex() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int index = 0;
    for (int i = 0; i < sibling.size(); i++) {
        if (this == sibling[i]) {
            index = i;
            break;
        }
    }
    return index;
}

bool Graphics::moveUpLevel() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int prevIndex = getPrevSibling();
    int index = getSiblingIndex();
    if (prevIndex < 0) return false;
    swap(sibling[prevIndex], sibling[index]);
    cg->setGraphics(sibling);
    return true;
}


bool Graphics::moveDownLevel() {
    CompositeGraphics *cg = this->getParent();
    vector<Graphics *> sibling = cg->getGraphics();
    int nextIndex = getNextSibling();
    int index = getSiblingIndex();
    if (nextIndex >= sibling.size()) return false;
    swap(sibling[nextIndex], sibling[index]);
    cg->setGraphics(sibling);
    return true;
}
