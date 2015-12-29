//
// Created by Red on 2015/11/18.
//

#ifndef VISITOR1013_2015_GUI_H
#define VISITOR1013_2015_GUI_H

#include <QtWidgets/QMainWindow>
#include <Qt>
#include <QGraphicsView>
#include <QtWidgets/QToolBar>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QtWidgets/qfiledialog.h>
#include "Painter.h"
#include "CommandManager.h"
#include "Model.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;


class Gui: public QMainWindow
{
    Q_OBJECT
public:
    Gui();
    virtual ~Gui();
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QWidget *widget;

    void Display();
    void CreateView();
    void MessageBox(const QString _message){};
    void CreateActions();
    void CreateMenus();
    void CreateToolBar();
    void SetActionConnection();
protected:
private:
    CommandManager *commandManager;
    Model *model;
    QAction *aboutDeveloper;
    QAction *loadFile;
    QAction *saveFile;
    QAction *drawCircle;
    QAction *drawSquare;
    QAction *drawRectangle;
    QAction *redo;
    QAction *undo;
    QAction *group;
    QAction *ungroup;
    QAction *deleteAction;
    QAction *moveUp;
    QAction *moveDown;
    QMenu *about;
    QMenu *file;
    QMenu *createShape;
    QToolBar *toolBar;
    Graphics *graphic;

private slots:
    void MessageDialog();
    string loadFileDialog();
    string saveFileDialog();
    void createCircle();
    void createSquare();
    void createRectangle();
    void triggerUndo();
    void triggerRedo();
    void triggerGrouping();
    void triggerUnGrouping();
    void triggerDeleting();
    void triggerMoveUp();
    void triggerMoveDown();
};


#endif //VISITOR1013_2015_GUI_H
