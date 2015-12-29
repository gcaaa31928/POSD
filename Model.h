//
// Created by Red on 2015/12/2.
//

#ifndef VISITOR1013_2015_MODEL_H
#define VISITOR1013_2015_MODEL_H

#include <vector>
#include "Graphics.h"
#include "CustomScene.h"
#include "Subject.h"
#include "AddCommand.h"
#include "GroupCommand.h"
#include "UngroupCommand.h"
#include "DeleteCommand.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "MoveCommand.h"

using namespace std;
class CustomScene;
class Model: public Subject {
public:
    void addGraphics(Graphics *);
    void addMultipleGraphics(vector<Graphics *> gs);
    void removeLastGraphics();
    void removeGraphics(Graphics *);
    void clearGraphics() {
        graphics_list.clear();
    }
    vector<Graphics *> getGraphicsList() const {
        return graphics_list;
    }
    void printState();
    Graphics*getSelectedGraphicsContainedPoint(QPointF) ;
    Graphics*getGraphicsContainedPoint(QPointF) ;
    void selectedGraphicsInRect(QRectF);
    void unselectAllGraphics();
    void unselectDeepSelectedGraphics(Graphics *graphics);
    void clearSceneItems();
    void redrawGraphics();
    Graphics * getDeepGraphics();

    void setScene(CustomScene *scene) {
        Model::scene = scene;
    }

    void setCommandManager(CommandManager *cm) {
        commandManager = cm;
    }

    CommandManager *getCommandManager() const {
        return commandManager;
    }

    void clearCommandManagerState() {
        commandManager->clear();
    }

    void addGraphics(SimpleGraphics *simpleGraphics){
        AddCommand *addCommand = new AddCommand(scene, this, simpleGraphics);
        commandManager->execute(addCommand);
        this->notifyObservers();
    }

    void moveGraphicsToPoint(Graphics *graphics, Painter *painter, QPointF pointF){
        MoveCommand *command = new MoveCommand(graphics, painter, pointF.x(), pointF.y());
        commandManager->execute(command);
        this->notifyObservers();

    }

    void undo() {
        commandManager->undo();
        this->notifyObservers();

    }

    void redo() {
        commandManager->redo();
        this->notifyObservers();

    }

    void grouping() {
        GroupCommand *command = new GroupCommand(scene, this);
        commandManager->execute(command);
        this->notifyObservers();
    }

    void unGrouping() {
        UngroupCommand *command = new UngroupCommand(scene, this);
        commandManager->execute(command);
        this->notifyObservers();
    }

    void deleting(){
        DeleteCommand *command = new DeleteCommand(scene, this);
        commandManager->execute(command);
        this->notifyObservers();
    }

    void moveUp(){
        MoveUpCommand *command = new MoveUpCommand(this);
        commandManager->execute(command);
        this->notifyObservers();

    }

    void moveDown(){
        MoveDownCommand *command = new MoveDownCommand(this);
        commandManager->execute(command);
        this->notifyObservers();

    }

private:
    vector<Graphics *> graphics_list;
    CustomScene *scene;
    CommandManager *commandManager;
};


#endif //VISITOR1013_2015_MODEL_H
