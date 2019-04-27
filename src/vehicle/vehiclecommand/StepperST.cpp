//
// Created by Fulva on 4/27/2019.
//

#include "StepperST.h"

StepperST::StepperST(AbstractVehicle &vehicle, const String &identifier, StepperFront &stepper, uint8_t multi)
        : VehicleCommand(
        vehicle, identifier), stepper(stepper), multi(multi) {}

void StepperST::execute(AbstractVehicle &vehicle, const int16_t *params) {
    stepper.setTarget(params[0] * multi);
}
