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



#endif //ROBOT_Z_COMMANDREGISTRY_H
