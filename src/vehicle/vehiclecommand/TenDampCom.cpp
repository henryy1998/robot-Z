//
// Created by fulva on 4/13/19.
//

#include "TenDampCom.h"

double const damping(0.95);

TenDampCom::TenDampCom(AbstractVehicle &vehicle, const String &identifier) : VehicleCommand(vehicle, identifier) {}

void TenDampCom::execute(AbstractVehicle &vehicle, const int16_t *params) {
    vehicle.getRightTen() = static_cast<uint8_t>(vehicle.getRightTen() * damping);
    vehicle.getLeftTen() = static_cast<uint8_t>(vehicle.getLeftTen() * damping);
}
