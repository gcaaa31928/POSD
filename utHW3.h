//
// Created by GCA on 2015/10/28.
//

#ifndef VISITOR1013_2015_UTHW3_H
#define VISITOR1013_2015_UTHW3_H

#include "cppunitlite/TestHarness.h"
#include "GraphicsFactory.h"
#include "SimpleGraphics.h"
#include <string>
#include <typeinfo>
#include <cstdio>

using namespace std;

TEST (GraphicsFactory, fileNotExist) {
    GraphicsFactory factory;
    try {
        factory.buildGraphicsFromFile("notExistFileName");
        FAIL("not thrown exception");
    } catch (string str) {
        CHECK(string("file is not exist") == str);
    }

}

TEST (GraphicsFactory, readStringCorrectly) {
    GraphicsFactory factory;
    string content = factory.fileContentsAsString("f1.txt");
    string ans = "C(0,0,50)\n"
                 "S(0,0,50)\n";
    CHECK(content == ans);
}

TEST (GraphicsFactory, extractShapeCorrectly) {
    GraphicsFactory factory;
    string c = "C(0,0,1)";
    int level;
    Graphics *g = factory.extractGraphicsFromOneLine(c, level);


    CHECK(typeid(*g) == typeid(SimpleGraphics));
    CHECK(typeid(*dynamic_cast<SimpleGraphics *>(g)->getShape()) == typeid(Circle));
    c = "S(-2,-2,2)";
    g = factory.extractGraphicsFromOneLine(c, level);
    CHECK(typeid(*g) == typeid(SimpleGraphics));
    CHECK(typeid(*dynamic_cast<SimpleGraphics *>(g)->getShape()) == typeid(Square));
    c = "R(-1,-1,1,3)";
    g = factory.extractGraphicsFromOneLine(c, level);
    CHECK(typeid(*g) == typeid(SimpleGraphics));
    CHECK(typeid(*dynamic_cast<SimpleGraphics *>(g)->getShape()) == typeid(Rectangle));
}

TEST (GraphicsFactory, extractShapeLevelCorrectly) {
    GraphicsFactory factory;
    string c = "C(0,0,1)";
    int level;
    Graphics *g = factory.extractGraphicsFromOneLine(c, level);
    LONGS_EQUAL(0, level);
    c = "  S(-2,-2,2)";
    g = factory.extractGraphicsFromOneLine(c, level);
    LONGS_EQUAL(1, level);
    c = "    R(-1,-1,1,3)";
    g = factory.extractGraphicsFromOneLine(c, level);
    LONGS_EQUAL(2, level);

}

TEST (GraphicsFactory, composite) {
    GraphicsFactory factory;
    stack<pair<Graphics *, int> > st;

    st.push(pair<Graphics *, int>(new CompositeGraphics(), 0));
    st.push(pair<Graphics *, int>(new CompositeGraphics(), 1));
    st.push(pair<Graphics *, int>(new CompositeGraphics(), 2));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Circle(0, 0, 1)), 3));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Rectangle(0, 0, 1, 1)), 3));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Square(0, 0, 1)), 3));
    int currentLevel = 1;
    factory.compose(st, currentLevel);
    DescriptionVisitor dv;
    Graphics *g = st.top().first;
    g->accept(dv);
    string ans = "Comp R(-1,-1,2,2)\n"
            "  Comp R(-1,-1,2,2)\n"
            "    C(0,0,1)\n"
            "    R(0,0,1,1)\n"
            "    S(0,0,1)\n";

    CHECK(ans == dv.getDescription());
    dv.clearState();
    st.pop();
    g = st.top().first;
    ans = "Comp R(0,0,0,0)\n";
    g->accept(dv);
    CHECK(ans == dv.getDescription());
}

TEST (GraphicsFactory, compositeWhenEndOfFile) {
    GraphicsFactory factory;
    stack<pair<Graphics *, int> > st;

    st.push(pair<Graphics *, int>(new CompositeGraphics(), 0));
    st.push(pair<Graphics *, int>(new CompositeGraphics(), 1));
    st.push(pair<Graphics *, int>(new CompositeGraphics(), 2));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Circle(0, 0, 1)), 3));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Rectangle(0, 0, 1, 1)), 3));
    st.push(pair<Graphics *, int>(new SimpleGraphics(new Square(0, 0, 1)), 3));
    int currentLevel = 0;
    factory.compose(st, currentLevel);
    DescriptionVisitor dv;
    Graphics *g = st.top().first;
    g->accept(dv);
    string ans = "Comp R(-1,-1,2,2)\n"
            "  Comp R(-1,-1,2,2)\n"
            "    Comp R(-1,-1,2,2)\n"
            "      C(0,0,1)\n"
            "      R(0,0,1,1)\n"
            "      S(0,0,1)\n";
    CHECK(ans == dv.getDescription());
}


TEST (GraphicsFactory, buildGraphicsFromFileCorrectly) {
    GraphicsFactory factory;
    try {
        Graphics *g = factory.buildGraphicsFromFile("f1.txt");
        DescriptionVisitor dv;
        string ans = "C(0,0,50)\n";

        g->accept(dv);
        CHECK(dv.getDescription() == ans);
    } catch (string res) {
        FAIL("do not throw exception if open file succses");
    }
}


TEST (GraphicsFactory, buildGraphicsFromFileCorrectly2) {
    GraphicsFactory factory;
    try {
        Graphics *g = factory.buildGraphicsFromFile("f2.txt");
        DescriptionVisitor dv;
        string ans = "Comp R(-100,-100,150,200)\n"
                    "  Comp R(-100,-100,150,150)\n"
                    "    C(0,0,50)\n"
                    "    S(-100,-100,100)\n"
                    "  R(-50,-50,50,150)\n";
        g->accept(dv);
        CHECK(dv.getDescription() == ans);
    } catch (string res) {
        cout<<res<<endl;
        FAIL("do not throw exception if open file succses");
    }
}

#endif //VISITOR1013_2015_UTHW3_H
