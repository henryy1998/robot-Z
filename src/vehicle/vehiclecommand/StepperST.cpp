//
// Created by Fulva on 4/27/2019.
//

#include "StepperST.h"

StepperST::StepperST(const String &identifier, StepperFront &stepper, uint8_t multi)
        : VehicleCommand(identifier), stepper(stepper), multi(multi) {}

void StepperST::execute(const int16_t *params) {
    stepper.setTarget(params[0] * multi);
}
