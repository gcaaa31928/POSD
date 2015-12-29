//
// Created by GCA on 2015/10/28.
//

#ifndef VISITOR1013_2015_GRAPHICSFACTORY_H
#define VISITOR1013_2015_GRAPHICSFACTORY_H
#include "Graphics.h"
#include "CompositeGraphics.h"
#include <string>
#include <stack>

class GraphicsFactory {
public:
    Graphics * buildGraphicsFromFile(const char * fileName);
    vector<Graphics *> buildMultipleGraphicsFromFile(const char * fileName);
    std::string fileContentsAsString(const char *fileName);
    Graphics * extractGraphicsFromOneLine(std::string& contents,int &level);
    void compose(stack<pair<Graphics*, int> > &st, int currentLevel);
};


#endif //VISITOR1013_2015_GRAPHICSFACTORY_H
