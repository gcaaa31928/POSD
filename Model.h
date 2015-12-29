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

class Model : public Subject {
public:

    Model() {
        _isChanged = false;
    };

    void pushGraphics(Graphics *);

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

    Graphics *getSelectedGraphicsContainedPoint(QPointF);

    Graphics *getGraphicsContainedPoint(QPointF);

    void selectedGraphicsInRect(QRectF);

    void unselectAllGraphics();

    void unselectDeepSelectedGraphics(Graphics *graphics);

    void clearSceneItems();

    void redrawGraphics();

    Graphics *getDeepGraphics();

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
        _redrawSign = false;
        this->notifyObservers();
    }

    void addGraphics(SimpleGraphics *simpleGraphics) {
        AddCommand *addCommand = new AddCommand(scene, this, simpleGraphics);
        commandManager->execute(addCommand);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void moveGraphicsToPoint(Graphics *graphics, Painter *painter, QPointF pointF) {
        MoveCommand *command = new MoveCommand(graphics, painter, pointF.x(), pointF.y());
        commandManager->execute(command);
        _redrawSign = false;
        this->notifyObservers();
        _isChanged = true;
    }

    void undo() {
        commandManager->undo();
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void redo() {
        commandManager->redo();
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void grouping() {
        GroupCommand *command = new GroupCommand(scene, this);
        commandManager->execute(command);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void unGrouping() {
        UngroupCommand *command = new UngroupCommand(scene, this);
        commandManager->execute(command);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void deleting() {
        DeleteCommand *command = new DeleteCommand(scene, this);
        commandManager->execute(command);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void moveUp() {
        MoveUpCommand *command = new MoveUpCommand(this);
        commandManager->execute(command);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void moveDown() {
        MoveDownCommand *command = new MoveDownCommand(this);
        commandManager->execute(command);
        _redrawSign = true;
        this->notifyObservers();
        _isChanged = true;
    }

    void graphicsSelectedStateChanged() {
        _redrawSign = false;
        this->notifyObservers();
    }

    bool isUndoEnable() {
        if (commandManager->isUndoEmpty()) {
            return false;
        }
        return true;
    }

    bool isRedoEnable() {
        if (commandManager->isRedoEmpty()) {
            return false;
        }
        return true;
    }

    bool isGroupEnable() {
        int count = 0;
        for (int i = 0; i < graphics_list.size(); i++) {
            if (graphics_list[i]->GetPainter()->is_selected()) {
                count++;
            }
        }
        return count >= 2;
    }

    bool isChanged() const {
        return _isChanged;
    }

    bool isRedrawSign() const {
        return _redrawSign;
    }

private:
    vector<Graphics *> graphics_list;
    CustomScene *scene;
    CommandManager *commandManager;
    bool _isChanged;
    bool _redrawSign;
public:
};


#endif //VISITOR1013_2015_MODEL_H
