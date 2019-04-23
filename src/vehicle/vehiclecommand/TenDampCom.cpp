//
// Created by fulva on 4/13/19.
//

#include "TenDampCom.h"

double const damping(0.95);

TenDampCom::TenDampCom(AbstractVehicle &vehicle, const String &identifier) : VehicleCommand(vehicle, identifier) {}

void TenDampCom::execute(AbstractVehicle &vehicle, const String params[5]) {
    vehicle.getRightTen() = static_cast<uint8_t>(vehicle.getRightTen() * damping);
    vehicle.getLeftTen() = static_cast<uint8_t>(vehicle.getLeftTen() * damping);
    vehicle.getForwardTen() = static_cast<uint8_t>(vehicle.getForwardTen() * damping);
    vehicle.getBackwardTen() = static_cast<uint8_t>(vehicle.getBackwardTen() * damping);
}
