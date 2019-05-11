//
// Created by fulva on 5/2/19.
//

#include <mechanism/StepperFront.h>
#include "StepperR.h"

StepperR::StepperR(CommandRegistry ident, StepperFront &stepper) : VehicleCommand(ident), stepper(stepper) {}

void StepperR::execute(const int16_t *params) {
    stepper.resetPos();
}
