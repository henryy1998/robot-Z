//
// Created by Fulva on 4/27/2019.
//

#include "StepperAc.h"

StepperAc::StepperAc(AbstractVehicle &vehicle, const String &identifier, StepperFront &stepper) : VehicleCommand(
        vehicle, identifier), stepper(stepper) {}

void StepperAc::execute(AbstractVehicle &vehicle, const int16_t *params) {
    stepper.activate();
}
