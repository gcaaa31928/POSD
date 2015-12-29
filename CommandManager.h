//
// Created by Red on 2015/12/1.
//

#ifndef VISITOR1013_2015_COMMANDMANAGER_H
#define VISITOR1013_2015_COMMANDMANAGER_H

#include "Command.h"
#include <stack>

using namespace std;

class CommandManager {
private:
    stack<Command *> m_undoCmds;
    stack<Command *> m_redoCmds;
public:
    CommandManager();

    ~CommandManager();

    void execute(Command *c);

    void redo();

    void undo();

    void clear();

    bool isUndoEmpty() {
        return m_undoCmds.empty();
    }

    bool isRedoEmpty() {
        return m_redoCmds.empty();
    }
};


#endif //VISITOR1013_2015_COMMANDMANAGER_H
