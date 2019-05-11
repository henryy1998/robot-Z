//
// Created by fulva on 4/28/19.
//

#include "Vehicle.h"

Vehicle::Vehicle() : index(0), vehicleComts{nullptr} {}

void Vehicle::attachVehicleComt(VehicleComt &vehicleComt) {
    vehicleComts[index] = &vehicleComt;
    index++;
}

void Vehicle::command(CommandRegistry identifier, const int16_t *params) {
    for (uint8_t i(0); i < index; i++) {
        vehicleComts[i]->command(identifier, params);
    }

}
