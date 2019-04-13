//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_COMMAND_H
#define ROBOT_Z_COMMAND_H


#include <WString.h>

class Command {
public:
    explicit Command(const String &identifier);

    String toString();

    virtual void execute() = 0;

private:
    String identifier;
};


#endif //ROBOT_Z_COMMAND_H
