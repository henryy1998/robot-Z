//
// Created by fulva on 4/28/19.
//

#include "VehicleComt.h"

void VehicleComt::command(const String &identifier, const int16_t *params) {
    for (uint8_t i = 0; i < index; i++) {
        if (commands[i]->toString() == identifier) {
            commands[i]->execute(params);
        }
    }
}

void VehicleComt::attachCommand(VehicleCommand &vehicleCommand) {
    commands[index] = &vehicleCommand;
    index++;
}
