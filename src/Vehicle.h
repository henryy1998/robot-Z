//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLE_H
#define ROBOT_Z_VEHICLE_H


#include <WString.h>
#include "Command.h"

class Vehicle {
public:
    void command(String command) {
    }

    virtual void configurate() = 0;

private:
    Command *commands[10];
};


#endif //ROBOT_Z_VEHICLE_H
