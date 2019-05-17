//
// Created by Fulva on 4/27/2019.
//

#include <HID.h>
#include "StepperFront.h"

#define DISTANCE 25
//#define DEBUG

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
#ifdef DEBUG
        Serial.println("step forward");
#endif
    } else if (distance < -DISTANCE) {
        stepper.step(-DISTANCE);
        curPos -= DISTANCE;
#ifdef DEBUG
        Serial.println("step backward");
#endif
    } else if (distance != 0) {
        stepper.step(distance);
        curPos = target;
#ifdef DEBUG
        Serial.println("step to the target");
#endif
    }
}

Stepper &StepperFront::getStepper() {
    return stepper;
}

void StepperFront::setSpeed(long speed) {
    stepper.setSpeed(speed);
}

void StepperFront::resetPos() {
#ifdef DEBUG
    Serial.println("reset pos");
#endif
    curPos = 0;
    target = 0;
}
