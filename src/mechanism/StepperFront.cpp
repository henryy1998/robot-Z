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
    if (target - curPos > DISTANCE) {
        stepper.step(DISTANCE);
        curPos += DISTANCE;
        Serial.println("step forward");
    } else if (target - curPos < -DISTANCE) {
        stepper.step(-DISTANCE);
        curPos -= DISTANCE;
        Serial.println("step backward");
    }
}

Stepper &StepperFront::getStepper() {
    return stepper;
}
