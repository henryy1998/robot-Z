//
// Created by fulva on 4/13/19.
//

#include "MotorActivateCom.h"

const static double damping = 0.3;

MotorActivateCom::MotorActivateCom(AbstractVehicle &vehicle, const String &identifier) : VehicleCommand(vehicle,
                                                                                                        identifier) {}

void MotorActivateCom::execute(AbstractVehicle &vehicle, const int16_t *params) {
    int16_t &leftSpeed = vehicle.getLeftMotorSpeed();
    int16_t const leftTen = vehicle.getLeftTen();
#ifdef DEBUG
    Serial.print("leftTen :");
    Serial.println(leftTen);
#endif
    double leftCre = damping * (leftTen - leftSpeed);
    leftSpeed = leftCre + leftSpeed;
    vehicle.getLeftMotor().drive(leftSpeed);
    Serial.print("left motor run at speed :");
    Serial.println(leftSpeed);

    
    int16_t &rightSpeed = vehicle.getRightMotorSpeed();
    int16_t const rightTen = vehicle.getRightTen();
    double rightCre = damping * (rightTen - rightSpeed);
    rightSpeed = rightCre + rightSpeed;
    vehicle.getRightMotor().drive(rightSpeed);
    Serial.print("right motor run at speed :");
    Serial.println(rightSpeed);
}
