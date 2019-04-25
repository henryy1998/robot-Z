//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_CONCRETEVEHICLE_H
#define ROBOT_Z_CONCRETEVEHICLE_H


#include <vehicle/vehiclecommand/TenChangeCom.h>
#include <vehicle/vehiclecommand/MotorActivateCom.h>
#include <vehicle/vehiclecommand/TenDampCom.h>
#include <vehicle/vehiclecommand/ServoControllCom.h>
#include "AbstractVehicle.h"

class ConcreteVehicle : public AbstractVehicle {
public:
    ConcreteVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1,
                    uint8_t rightPin2, uint8_t rightPinEna, uint8_t servoPin);

    void update() override;

private:
    TenChangeCom left;
    TenChangeCom right;
    MotorActivateCom leftMotorActivateCom;
    MotorActivateCom rightMotorActivateCom;
    ServoControllCom servoControllCom;
};


#endif //ROBOT_Z_CONCRETEVEHICLE_H
