//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_ABSTRACTVEHICLE_H
#define ROBOT_Z_ABSTRACTVEHICLE_H


#include <WString.h>
#include <Servo.h>
#include "behavior/Command.h"
#include "mechanism/Motor.h"
#include <Stepper.h>

class AbstractVehicle {
public:
    AbstractVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1, uint8_t rightPin2,
                    uint8_t rightPinEna, uint8_t servoPin);

    void command(const String &command, const int16_t params[5]) {
        for (Command *command1:commands) {
            if (command1->toString() == command) {
                command1->execute(params);
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

    int16_t &getRightTen() {
        return rightTen;
    }

    int16_t &getLeftTen() {
        return leftTen;
    }

    Command **const getCommands() {
        return commands;
    }

    int16_t &getRightMotorSpeed() {
        return rightMotorSpeed;
    }

    int16_t &getLeftMotorSpeed() {
        return leftMotorSpeed;
    }

    Servo &getServo() {
        return servo;
    }

private:
    Command *commands[10]{};
    int16_t rightTen{0};
    int16_t leftTen{0};
    int16_t rightMotorSpeed{0};
    int16_t leftMotorSpeed{0};
    Motor leftMotor;
    Motor rightMotor;
    Servo servo;

};


#endif //ROBOT_Z_ABSTRACTVEHICLE_H
