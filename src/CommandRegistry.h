//
// Created by User on 2019/5/11.
//

#ifndef ROBOT_Z_COMMANDREGISTRY_H
#define ROBOT_Z_COMMANDREGISTRY_H


#include <WString.h>


enum class CommandRegistry {
    NULLCOMMAND,
    LEFT_MOTOR_AC,
    RIGHT_MOTOR_AC,
    LEFT_MOTOR_SS,
    RIGHT_MOTOR_SS,
    SERVO1A,
    SERVO1SS,
    SERVO2A,
    SERVO2_RESET,
    SERVO2_SS,
    SERVO3A,
    SERVO3_RESET,
    SERVO3_SS
};

struct CommandNode {
    CommandRegistry command;
    String ident;

    CommandNode(CommandRegistry command, const String &ident) : command(command), ident(ident) {}
};

CommandNode commands[]{
        {CommandRegistry::LEFT_MOTOR_AC,  "leftA"},
        {CommandRegistry::LEFT_MOTOR_SS,  "left"},
        {CommandRegistry::RIGHT_MOTOR_AC, "rightA"},
        {CommandRegistry::RIGHT_MOTOR_SS, "right"},
        {CommandRegistry::SERVO1A,        "servo1a"},
        {CommandRegistry::SERVO1SS,       "servo1"},
        {CommandRegistry::SERVO2A,        "servo2a"},
        {CommandRegistry::SERVO2_SS,      "servo2"},
        {CommandRegistry::SERVO2_RESET,   "servo2r"},
        {CommandRegistry::SERVO3A,        "servo3a"},
        {CommandRegistry::SERVO3_SS,      "servo3"},
        {CommandRegistry::SERVO3_RESET,   "servo3r"}
};

CommandRegistry resolveCommand(const String &ident) {
    CommandRegistry command{CommandRegistry::NULLCOMMAND};
    for (CommandNode aCom:commands) {
        if (aCom.ident == ident) {
            return aCom.command;
        }
    }
}

#endif //ROBOT_Z_COMMANDREGISTRY_H
