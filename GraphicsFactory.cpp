//
// Created by GCA on 2015/10/28.
//

#include "GraphicsFactory.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Square.h"
#include "DescriptionVisitor.h"
#include <utility>
#include <algorithm>

using namespace std;

void GraphicsFactory::compose(stack<pair<Graphics *, int> > &st, int currentLevel) {
    if (st.empty())return;
    int tmpLevel = st.top().second; //level

    vector<Graphics *> childGraphics;
    while (!st.empty()) {
        if (tmpLevel != st.top().second) {
            // find parent node
            Graphics *parent = st.top().first;
            while(!childGraphics.empty()) {
                Graphics *child = childGraphics.back();
                childGraphics.pop_back();
                parent->add(child);
            }
            tmpLevel = st.top().second;
            childGraphics.clear();
        }
        if (currentLevel >= st.top().second) break;
        childGraphics.push_back(st.top().first);
        st.pop();
    }
}


vector<Graphics *> GraphicsFactory::buildMultipleGraphicsFromFile(const char *fileName) {
    fstream fs;
    fs.open(fileName);

    if (!fs.is_open()) {
        throw string("file is not exist");
    }
    fs.close();
    string contents = fileContentsAsString(fileName);
    stringstream ss(contents);
    string line;
    int currentLevel = 0, topLevel = 0;
    stack<pair<Graphics *, int> > st;
    while (getline(ss, line)) {

        Graphics *g = extractGraphicsFromOneLine(line, currentLevel);
        compose(st, currentLevel);
        st.push(pair<Graphics *, int>(g, currentLevel));
    }
    compose(st, 0);
    vector<Graphics *> gs;
    while(!st.empty()){
        DescriptionVisitor dv;
        st.top().first->accept(dv);
        gs.push_back(st.top().first);
        st.pop();
    }
    std::reverse(gs.begin(), gs.end());
    return gs;
}

Graphics * GraphicsFactory::buildGraphicsFromFile(const char *fileName) {
    vector<Graphics *> gs = buildMultipleGraphicsFromFile(fileName);
    return gs[0];
}

std::string GraphicsFactory::fileContentsAsString(const char *fileName) {
    fstream fs;
    stringstream buffer;

    fs.open(fileName);

    buffer << fs.rdbuf();
    string contents(buffer.str());
    string ans;
    for (int i = 0; i < contents.size(); i++) {
        if (contents[i] == '\r')continue;
        ans += contents[i];
    }
    fs.close();
    return ans;
}

Graphics *GraphicsFactory::extractGraphicsFromOneLine(std::string &contents, int &level) {
    int count = 0;
    for (int i=0;i<contents.size();i++) {
        char c = contents[i];
        if (c == ' ')count++;
        else break;
    }

    level = count >> 1;
    string substring = contents.substr(count);
    stringstream ss(substring);
    int loc = substring.find("Comp");
    if (loc != string::npos) {
        return new CompositeGraphics();
    }
    loc = substring.find("C");
    if (loc != string::npos) {
        int x, y, r;
        sscanf(substring.c_str(), "C(%d,%d,%d)", &x, &y, &r);
        SimpleGraphics *sg = new SimpleGraphics(new Circle(x, y, r));
        return sg;
    }
    loc = substring.find("S");
    if (loc != string::npos) {
        int x, y, l;
        sscanf(substring.c_str(), "S(%d,%d,%d)", &x, &y, &l);
        SimpleGraphics *sg = new SimpleGraphics(new Square(x, y, l));
        return sg;
    }
    loc = substring.find("R");
    if (loc != string::npos) {
        int x, y, l, w;
        sscanf(substring.c_str(), "R(%d,%d,%d,%d)", &x, &y, &l, &w);
        SimpleGraphics *sg = new SimpleGraphics(new Rectangle(x, y, l, w));
        return sg;
    }
}
