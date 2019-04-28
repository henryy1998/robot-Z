//
// Created by Fulva on 4/27/2019.
//

#include "StepperAc.h"

StepperAc::StepperAc(AbstractVehicle &vehicle, const String &identifier, StepperFront &stepper) : VehicleCommand(
        identifier), stepper(stepper) {}

void StepperAc::execute(const int16_t *params) {
    stepper.activate();
}
