//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLE_H
#define ROBOT_Z_VEHICLE_H


#include <WString.h>
#include "Command.h"
#include "Motor.h"

class Vehicle {
public:
    Vehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1, uint8_t rightPin2,
            uint8_t rightPinEna) : leftMotor(leftPinEna, leftPin1, leftPin2),
                                   rightMotor(rightPinEna, rightPin1, rightPin2) {}

    void command(String command) {
    }

    virtual void configurate() = 0;

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

private:
    Command *commands[10];
    uint8_t rightTen;
    uint8_t leftTen;
    uint8_t forwardTen;
    uint8_t backwardTen;
    Motor leftMotor;
    Motor rightMotor;
};


#endif //ROBOT_Z_VEHICLE_H
