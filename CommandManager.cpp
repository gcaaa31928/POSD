//
// Created by Red on 2015/12/1.
//

#include <stdio.h>
#include "CommandManager.h"

CommandManager::CommandManager() {
}

CommandManager::~CommandManager() {
    while (!m_undoCmds.empty()) {
        Command *c = m_undoCmds.top();
        m_undoCmds.pop();
        delete c;
    }
    while (!m_redoCmds.empty()) {
        Command *c = m_redoCmds.top();
        m_redoCmds.pop();
        delete c;
    }
}

void CommandManager::execute(Command *cmd) {
    if (cmd->isFailed()) {
        return;
    }
    cmd->execute();
    if (cmd->isFailed()) {
        return;
    }
    m_undoCmds.push(cmd);
    // cleanup and release redoable commands
    while (!m_redoCmds.empty()) {
        Command *c = m_redoCmds.top();
        m_redoCmds.pop();
        delete c;
    }
}

void CommandManager::redo() {
    if (m_redoCmds.size() == 0)
        return; // or throw exception

    Command *c = m_redoCmds.top();
    m_redoCmds.pop();
    c->execute(); // redo the command
    m_undoCmds.push(c);
}

void CommandManager::undo() {
    if (m_undoCmds.size() == 0)
        return;

    Command *c = m_undoCmds.top();
    m_undoCmds.pop();
    c->unexecute(); // undo the command
    m_redoCmds.push(c);
}

void CommandManager::clear() {
    while (!m_undoCmds.empty()) {
        m_undoCmds.pop();
    }
    while (!m_redoCmds.empty()) {
        m_redoCmds.pop();
    }
}
