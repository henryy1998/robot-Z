//
// Created by fulva on 4/28/19.
//

#include "VehicleComt.h"


void VehicleComt::attachCommand(VehicleCommand &vehicleCommand) {
    commands[index] = &vehicleCommand;
    index++;
}

VehicleComt::VehicleComt() : index(0), commands{nullptr} {}
