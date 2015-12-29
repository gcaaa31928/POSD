//
// Created by Red on 2015/12/1.
//

#ifndef VISITOR1013_2015_COMMAND_H
#define VISITOR1013_2015_COMMAND_H

#include <string>

using namespace std;

class Command {
public:
    Command(){
        failed = false;
    };

    virtual ~Command(){};

    virtual void execute() = 0;

    virtual void unexecute() = 0;

    bool isFailed() const {
        return failed;
    }

protected:
    bool failed;
};

#endif //VISITOR1013_2015_COMMAND_H
