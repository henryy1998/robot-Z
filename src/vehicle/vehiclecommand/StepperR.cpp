//
// Created by fulva on 5/2/19.
//

#include "StepperR.h"

StepperR::StepperR(const String &identifier, StepperFront &stepper) : VehicleCommand(identifier), stepper(stepper) {}

void StepperR::execute(const int16_t *params) {
    stepper.resetPos();
}
