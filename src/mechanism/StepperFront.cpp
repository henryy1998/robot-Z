//
// Created by Fulva on 4/27/2019.
//

#include <HID.h>
#include "StepperFront.h"

StepperFront::StepperFront(Stepper stepper) :
        stepper(stepper), curPos(0), target(0) {}

void StepperFront::setTarget(int16_t target) {
    this->target = target;
}

void StepperFront::activate() {
    if (target - curPos > 0) {
        stepper.step(1);
        curPos++;
        Serial.println("step forward");
    } else if (target - curPos < 0) {
        stepper.step(-1);
        curPos--;
        Serial.println("step backward");
    }
}
