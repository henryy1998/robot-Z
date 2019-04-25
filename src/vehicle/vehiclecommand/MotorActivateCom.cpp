//
// Created by fulva on 4/13/19.
//

#include "MotorActivateCom.h"

const static double damping = 0.3;

MotorActivateCom::MotorActivateCom(AbstractVehicle &vehicle, const String &identifier, Motor &motor,
                                   const int16_t &target,
                                   int16_t &cSpeed) :
        VehicleCommand(vehicle, identifier),
        motor(motor),
        target(target),
        cSpeed(cSpeed) {}

void MotorActivateCom::execute(AbstractVehicle &vehicle, const int16_t *params) {
    double cre = damping * (target - cSpeed);
    cSpeed = cre + cSpeed;
    motor.drive(cSpeed);
    Serial.print("drive motor run at speed :");
    Serial.println(cSpeed);
}
