//
// Created by Fulva on 4/27/2019.
//

#include <HID.h>
#include "StepperFront.h"

StepperFront::StepperFront(AccelStepper stepper) :
        stepper(stepper) {}

void StepperFront::setTarget(int16_t target) {
    stepper.moveTo(target);
}

void StepperFront::activate() {
    stepper.run();
}

AccelStepper &StepperFront::getStepper() {
    return stepper;
}

void StepperFront::setSpeed(long speed) {
    stepper.setSpeed(speed);
    stepper.setMaxSpeed(speed);
}

void StepperFront::setAccel(float accel) {
    stepper.setAcceleration(accel);

}
