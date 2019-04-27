//
// Created by Fulva on 4/27/2019.
//

#include "StepperST.h"

StepperST::StepperST(AbstractVehicle &vehicle, const String &identifier, StepperFront &stepper) : VehicleCommand(
        vehicle, identifier), stepper(stepper) {}

void StepperST::execute(AbstractVehicle &vehicle, const int16_t *params) {
    stepper.setTarget(params[0]);
}
