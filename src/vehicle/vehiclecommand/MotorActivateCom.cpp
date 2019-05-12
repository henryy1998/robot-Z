//
// Created by fulva on 4/13/19.
//

#include "MotorActivateCom.h"

const static double damping = 0.3;

MotorActivateCom::MotorActivateCom(CommandRegistry ident, Motor &motor, const int16_t &target, int16_t &cSpeed) :
        VehicleCommand(ident),
        motor(motor),
        target(target),
        cSpeed(cSpeed) {}

void MotorActivateCom::execute(const int16_t *params) {
    double cre = damping * (target - cSpeed);
    cSpeed = cre + cSpeed;
    motor.drive(cSpeed);
#ifdef DEBUG
    Serial.print("drive motor run at speed :");
    Serial.println(cSpeed);
#endif
}
