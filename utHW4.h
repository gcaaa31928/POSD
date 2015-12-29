//
// Created by Red on 2015/11/18.
//

#ifndef VISITOR1013_2015_UTHW4_H
#define VISITOR1013_2015_UTHW4_H

#include "cppunitlite/TestHarness.h"

#include "Gui.h"
#include <QApplication>

int argc = 0;
char a[2] = {'0', '1'};
char *argv[1] = {a};

TEST (TryQt, third) {
    QApplication app(argc, argv);
    Gui gui;

    gui.show();
    app.exec();
}

//TEST (TryQt, fourth) {
//    QApplication a(argc, argv);
//    QGraphicsScene scene;
//    QGraphicsView view(&scene);
//    QGraphicsPixmapItem item(QPixmap(".\\loadFile.png"));
//    scene.addItem(&item);
//    view.show();
//    a.exec();
//}


#endif //VISITOR1013_2015_UTHW4_H
