//
// Created by GCA on 2015/10/14.
//

#ifndef VISITOR1013_2015_DESCRIPTIONVISITOR_H
#define VISITOR1013_2015_DESCRIPTIONVISITOR_H


#include <iostream>
#include <cstdio>
#include "GraphicsVisitor.h"

using namespace std;

class DescriptionVisitor : public GraphicsVisitor {
public:
    DescriptionVisitor() : des("") {
        indentsCount.clear();
        indentsLineCount.clear();
    }

    void visitSimpleGraphics(SimpleGraphics *s) {
        if (indentsCount.size()) {
            for (int i = 0; i < indentsCount.back(); i++)
                des = des + " ";
            indentsLineCount.back()--;
            while (!indentsLineCount.empty() && indentsLineCount.back() == 0) {
                indentsLineCount.pop_back();
                indentsCount.pop_back();
            }
        }
        des = des + s->getShape()->describe() + "\n";
    }

    void visitCompositeGraphics(CompositeGraphics *c) {
        if (indentsCount.size()) {
            for (int i = 0; i < indentsCount.back(); i++)
                des = des + " ";
            indentsLineCount.back()--;
        }
        des = des + "Comp " + c->getBoundingBox().describe() + "\n";
        if (indentsCount.empty())
            indentsCount.push_back(2);
        else {
            int indent = indentsCount.back();
            indentsCount.push_back(indent + 2);
        }
        indentsLineCount.push_back(c->getGraphics().size());
        while (!indentsLineCount.empty() && indentsLineCount.back() == 0) {
            indentsLineCount.pop_back();
            indentsCount.pop_back();
        }
    }

    string getDescription() {
        return des;
    }
    void clearState() {
        des="";
        indentsCount.clear();
        indentsLineCount.clear();
    }

private:

    string des;
    vector<int> indentsCount;
    vector<int> indentsLineCount;
};


#endif //VISITOR1013_2015_DESCRIPTIONVISITOR_H
