//
// Created by fulva on 4/13/19.
//

#include "ConcreteVehicle.h"

ConcreteVehicle::ConcreteVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1,
                                 uint8_t rightPin2, uint8_t rightPinEna, uint8_t servoPin, const Stepper &stepper1,
                                 const Stepper &stepper2) :
        AbstractVehicle(leftPin1, leftPin2,
                        leftPinEna, rightPin1,
                        rightPin2, rightPinEna, servoPin, stepper1, stepper2),
        left("left", this->getLeftTen()),
        right("right", this->getRightTen()),
        leftMotorActivateCom("leftA", this->getLeftMotor(), this->getLeftTen(), this->getLeftMotorSpeed()),
        rightMotorActivateCom("rightA", this->getRightMotor(), this->getRightTen(), this->getRightMotorSpeed()),
        servoControllCom("servo1", this->getServo()),
        stepperAc1("servo2a", getStepper1()),
        stepperAc2("servo3a", getStepper2()),
        stepperSt1("servo2", getStepper1(), 25),
        stepperSt2("servo3", getStepper2(), 25) {
    Command **const commands = getCommands();
    commands[0] = &left;
    commands[1] = &right;
    commands[2] = &servoControllCom;
    commands[3] = &leftMotorActivateCom;
    commands[4] = &rightMotorActivateCom;
    commands[5] = &stepperAc1;
    commands[6] = &stepperAc2;
    commands[7] = &stepperSt1;
    commands[8] = &stepperSt2;
}
