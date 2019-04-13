//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_ABSTRACTVEHICLE_H
#define ROBOT_Z_ABSTRACTVEHICLE_H


#include <WString.h>
#include "behavior/Command.h"
#include "mechanism/Motor.h"

class AbstractVehicle {
public:
    AbstractVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1, uint8_t rightPin2,
                    uint8_t rightPinEna) : leftMotor(leftPinEna, leftPin1, leftPin2),
                                           rightMotor(rightPinEna, rightPin1, rightPin2) {
    }

    void command(const String &command) {
        for (Command *command1:commands) {
            if (command1->toString() == command) {
                command1->execute();
            }
        }
    }

    virtual void update() = 0;


    Motor &getLeftMotor() {
        return leftMotor;
    }

    Motor &getRightMotor() {
        return rightMotor;
    }

    uint8_t &getRightTen() {
        return rightTen;
    }

    uint8_t &getLeftTen() {
        return leftTen;
    }

    uint8_t &getForwardTen() {
        return forwardTen;
    }

    uint8_t &getBackwardTen() {
        return backwardTen;
    }

    Command **const getCommands() {
        return commands;
    }

private:
    Command *commands[10];
    uint8_t rightTen{0};
    uint8_t leftTen{0};
    uint8_t forwardTen{0};
    uint8_t backwardTen{0};
    Motor leftMotor;
    Motor rightMotor;
};


#endif //ROBOT_Z_ABSTRACTVEHICLE_H
