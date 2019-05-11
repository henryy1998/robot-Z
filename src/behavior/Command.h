//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_COMMAND_H
#define ROBOT_Z_COMMAND_H


#include <WString.h>
#include <CommandRegistry.h>

class Command {
public:
    explicit Command(CommandRegistry ident);

    const CommandRegistry getIdent();

    virtual void execute(const int16_t params[5]) = 0;

private:
    CommandRegistry identifier;
};


#endif //ROBOT_Z_COMMAND_H
