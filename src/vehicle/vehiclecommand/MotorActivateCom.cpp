//
// Created by fulva on 4/13/19.
//

#include "MotorActivateCom.h"

MotorActivateCom::MotorActivateCom(AbstractVehicle &vehicle, const String &identifier) : VehicleCommand(vehicle,
                                                                                                        identifier) {}

void MotorActivateCom::execute(AbstractVehicle &vehicle) {
    int16_t leftSpeed =
            vehicle.getForwardTen() - vehicle.getBackwardTen() + vehicle.getRightTen() - vehicle.getLeftTen();
    vehicle.getLeftMotor().drive(leftSpeed);
    int16_t rightSpeed =
            vehicle.getBackwardTen() - vehicle.getBackwardTen() + vehicle.getLeftTen() - vehicle.getRightTen();
    vehicle.getRightMotor().drive(rightSpeed);
}
