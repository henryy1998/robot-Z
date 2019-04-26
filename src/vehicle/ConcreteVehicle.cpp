//
// Created by fulva on 4/13/19.
//

#include "ConcreteVehicle.h"

ConcreteVehicle::ConcreteVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1,
                                 uint8_t rightPin2, uint8_t rightPinEna, uint8_t servoPin) :
        AbstractVehicle(leftPin1, leftPin2,
                        leftPinEna, rightPin1,
                        rightPin2, rightPinEna, servoPin),
        left(*this, "left", this->getLeftTen()),
        right(*this, "right", this->getRightTen()),
        leftMotorActivateCom(*this, "leftA", this->getLeftMotor(), this->getLeftTen(), this->getLeftMotorSpeed()),
        rightMotorActivateCom(*this, "rightA", this->getRightMotor(), this->getRightTen(), this->getRightMotorSpeed()),

        servoControllCom(*this, "servo1", this->getServo()) {
    Command **const commands = getCommands();
    commands[0] = &left;
    commands[1] = &right;
    commands[2] = &servoControllCom;
    commands[3] = &leftMotorActivateCom;
    commands[4] = &rightMotorActivateCom;
}
