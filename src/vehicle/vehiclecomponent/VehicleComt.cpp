//
// Created by fulva on 4/28/19.
//

#include "VehicleComt.h"

void VehicleComt::command(CommandRegistry identifier, const int16_t *params) {
    for (uint8_t i(0); i < index; i++) {
        if (commands[i]->getIdent() == identifier) {
            commands[i]->execute(params);
        }
    }
}

void VehicleComt::attachCommand(VehicleCommand &vehicleCommand) {
    commands[index] = &vehicleCommand;
    index++;
}

VehicleComt::VehicleComt() : index(0), commands{nullptr} {}
