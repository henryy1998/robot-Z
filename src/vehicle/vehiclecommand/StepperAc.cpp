//
// Created by Fulva on 4/27/2019.
//

#include "StepperAc.h"

StepperAc::StepperAc(CommandRegistry ident, StepperFront &stepper) : VehicleCommand(
        ident), stepper(stepper) {}

void StepperAc::execute(const int16_t *params) {
    stepper.activate();
}
