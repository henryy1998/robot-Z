//
// Created by fulva on 4/12/19.
//

#include "AbstractVehicle.h"

AbstractVehicle::AbstractVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1,
                                 uint8_t rightPin2, uint8_t rightPinEna, uint8_t servoPin, Stepper stepper1,
                                 Stepper stepper2) :
        leftMotor(leftPinEna, leftPin1, leftPin2),
        rightMotor(rightPinEna, rightPin1, rightPin2),
        stepper1(AccelStepper()),
        stepper2(AccelStepper()) {
    servo.attach(servoPin);
    this->getStepper1().getStepper().setSpeed(500);
    this->getStepper2().getStepper().setSpeed(500);
}
