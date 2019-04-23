//
// Created by fulva on 4/12/19.
//

#include "VehicleCommand.h"

void VehicleCommand::execute(const int16_t *params) {
    execute(vehicle, params);
}