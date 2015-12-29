//
// Created by Red on 2015/11/18.
//


#include <fstream>
#include "Gui.h"
#include "GraphicsItemFactory.h"
#include "Circle.h"
#include "Square.h"
#include "GraphicsFactory.h"
#include "PaintVisitor.h"
#include "DescriptionVisitor.h"
#include "SquarePainter.h"
#include "CirclePainter.h"
#include "RectanglePainter.h"
#include "AddCommand.h"
#include "GroupCommand.h"
#include "UngroupCommand.h"
#include "DeleteCommand.h"
#include "CustomScene.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"

Gui::Gui() {
//    ctor
    commandManager = new CommandManager();
    model = new Model();
    model->setCommandManager(commandManager);
    CreateView();
    CreateActions();
    CreateMenus();
    CreateToolBar();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    Display();

}

Gui::~Gui() {
    delete widget;
    delete scene;
    //dtor
}

void Gui::CreateView() {
    widget = new QWidget();//ø�spainter item������
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);//�n�վ�ͦ�����m
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new CustomScene(model);//�޲zpainter item������
    model->setScene((CustomScene *)scene);
    scene->setSceneRect(0, 0, 800, 600);
    graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//�e�{�e��
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void Gui::CreateActions() {
    aboutDeveloper = new QAction("aboutDeveloper", widget);
    loadFile = new QAction("Load File", widget);
    loadFile->setIcon(QIcon("loadFile.png"));
    saveFile = new QAction("Save File", widget);
    saveFile->setIcon(QIcon("saveFile.png"));
    drawCircle = new QAction("createCircle", widget);
    drawCircle->setIcon(QIcon("circle.png"));
    drawSquare = new QAction("createSquare", widget);
    drawSquare->setIcon(QIcon("square.png"));
    drawRectangle = new QAction("createRectangle", widget);
    drawRectangle->setIcon(QIcon("rectangle.png"));
    undo = new QAction("Undo", widget);
    undo->setIcon(QIcon("undo.png"));
    redo = new QAction("Redo", widget);
    redo->setIcon(QIcon("redo.png"));
    group = new QAction("Group", widget);
    group->setIcon(QIcon("group.png"));
    ungroup = new QAction("Ungroup", widget);
    ungroup->setIcon(QIcon("ungroup.png"));
    deleteAction = new QAction("Ungroup", widget);
    deleteAction->setIcon(QIcon("delete.png"));
    moveUp = new QAction("MoveUp", widget);
    moveUp->setIcon(QIcon("moveUp.png"));
    moveDown = new QAction("MoveDown", widget);
    moveDown->setIcon(QIcon("moveDown.png"));
}

void Gui::SetActionConnection() {
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(loadFile, SIGNAL(triggered()), this, SLOT(loadFileDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(saveFileDialog()));
    connect(drawCircle, SIGNAL(triggered()), this, SLOT(createCircle()));
    connect(drawSquare, SIGNAL(triggered()), this, SLOT(createSquare()));
    connect(drawRectangle, SIGNAL(triggered()), this, SLOT(createRectangle()));
    connect(undo, SIGNAL(triggered()), this, SLOT(triggerUndo()));
    connect(redo, SIGNAL(triggered()), this, SLOT(triggerRedo()));
    connect(group, SIGNAL(triggered()), this, SLOT(triggerGrouping()));
    connect(ungroup, SIGNAL(triggered()), this, SLOT(triggerUnGrouping()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(triggerDeleting()));
    connect(moveUp, SIGNAL(triggered()), this, SLOT(triggerMoveUp()));
    connect(moveDown, SIGNAL(triggered()), this, SLOT(triggerMoveDown()));

}


void Gui::CreateMenus() {
    file = menuBar()->addMenu("File");
    file->addAction(loadFile);
    file->addAction(saveFile);
    about = menuBar()->addMenu("About");
    about->addAction(aboutDeveloper);
    createShape = menuBar()->addMenu("Create Shape");
    createShape->addAction(drawSquare);
    createShape->addAction(drawRectangle);
    createShape->addAction(drawCircle);

}

void Gui::CreateToolBar() {
    toolBar = addToolBar("main toolbar");
    toolBar->addAction(loadFile);
    toolBar->addAction(saveFile);
    toolBar->addAction(drawSquare);
    toolBar->addAction(drawRectangle);
    toolBar->addAction(drawCircle);
    toolBar->addAction(undo);
    toolBar->addAction(redo);
    toolBar->addAction(group);
    toolBar->addAction(ungroup);
    toolBar->addAction(deleteAction);
    toolBar->addAction(moveUp);
    toolBar->addAction(moveDown);
}

void Gui::Display() {
    scene->update();
//    Painter *item = new Painter(0,0, 200, 100, widget);

}

void Gui::MessageDialog() {
    QMessageBox msgbox;
    std::string message("104598037\n");
    message += std::string("author:黃泓鳴\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}

string Gui::saveFileDialog() {
    QString fn = QFileDialog::getSaveFileName(this, tr("Save File..."),
                                              QString(), tr("Txt (*.txt)"));
    string fileName;
    fileName = fn.toUtf8().constData();
//    if (fn.isEmpty()) {
//    }

    string fileContent = "";
    vector<Graphics *> gs = model->getGraphicsList();
    for (int i = 0; i < gs.size(); i++) {
        DescriptionVisitor dv;
        gs[i]->accept(dv);
        fileContent += dv.getDescription();
    }

    fstream fp;
    if (fileName != "") {
        fp.open(fileName.c_str(), ios::out);
        fp << fileContent;
        fp.close();
        commandManager->clear();
        cout << "Save File" << endl;
    }
    return "";
}

string Gui::loadFileDialog() {
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("Txt (*.txt)"));
    string fileName;
    if (!fn.isEmpty()) {
        fileName = fn.toUtf8().constData();
    }
    else {
        return "";
    }
    GraphicsFactory *graphicsFactory = new GraphicsFactory();

    scene->clear();
    DescriptionVisitor dv;
    vector<Graphics *> gs = graphicsFactory->buildMultipleGraphicsFromFile(fileName.c_str());
    model->clearGraphics();
    model->addMultipleGraphics(gs);
    for (int i = 0; i < gs.size(); i++) {
        PaintVisitor paintVisitor(model);
        paintVisitor.setScene(scene);
        gs[i]->accept(paintVisitor);
        paintVisitor.Draw();
    }


    return "";
}

void Gui::createRectangle() {
    SimpleGraphics *sg = new SimpleGraphics(new Rectangle(400, 300, 100, 50));
    model->addGraphics(sg);
}

void Gui::createCircle() {
    SimpleGraphics *sg = new SimpleGraphics(new Circle(400, 300, 50));
    model->addGraphics(sg);
}

void Gui::createSquare() {
    SimpleGraphics *sg = new SimpleGraphics(new Square(400, 300, 50));
    model->addGraphics(sg);
}


void Gui::triggerUndo() {
    model->undo();
}

void Gui::triggerRedo() {
    model->redo();
}


void Gui::triggerGrouping() {
    model->grouping();
}

void Gui::triggerUnGrouping() {
    model->unGrouping();
}

void Gui::triggerDeleting() {
    model->deleting();
}

void Gui::triggerMoveUp() {
    model->moveUp();
}

void Gui::triggerMoveDown() {
    model->moveDown();
}


