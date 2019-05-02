//
// Created by Fulva on 4/27/2019.
//

#include <HID.h>
#include "StepperFront.h"

#define DISTANCE 25

StepperFront::StepperFront(Stepper stepper) :
        stepper(stepper), curPos(0), target(0) {}

void StepperFront::setTarget(int16_t target) {
    this->target = target;
}

void StepperFront::activate() {
    int16_t distance = target - curPos;
    if (distance > DISTANCE) {
        stepper.step(DISTANCE);
        curPos += DISTANCE;
        Serial.println("step forward");
    } else if (distance < -DISTANCE) {
        stepper.step(-DISTANCE);
        curPos -= DISTANCE;
        Serial.println("step backward");
    } else if (distance != 0) {
        stepper.step(distance);
        curPos = target;
        Serial.println("step to the target");
    }
}

Stepper &StepperFront::getStepper() {
    return stepper;
}

void StepperFront::setSpeed(long speed) {
    stepper.setSpeed(speed);
}

void StepperFront::resetPos() {
    curPos = 0;
    target = 0;
}
