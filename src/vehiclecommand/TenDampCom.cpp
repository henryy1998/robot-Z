//
// Created by fulva on 4/13/19.
//

#include "TenDampCom.h"

TenDampCom::TenDampCom(Vehicle &vehicle, const String &identifier) : VehicleCommand(vehicle, identifier) {}

void TenDampCom::execute(Vehicle &vehicle) {
    vehicle.getRightTen() = static_cast<uint8_t>(vehicle.getRightTen() * 0.5);
    vehicle.getLeftTen() = static_cast<uint8_t>(vehicle.getLeftTen() * 0.5);
    vehicle.getForwardTen() = static_cast<uint8_t>(vehicle.getForwardTen() * 0.5);
    vehicle.getBackwardTen() = static_cast<uint8_t>(vehicle.getBackwardTen() * 0.5);
}
