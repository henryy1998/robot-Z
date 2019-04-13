//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_CONCRETEVEHICLE_H
#define ROBOT_Z_CONCRETEVEHICLE_H


#include <vehicle/vehiclecommand/TenChangeCom.h>
#include <vehicle/vehiclecommand/MotorActivateCom.h>
#include <vehicle/vehiclecommand/TenDampCom.h>
#include "AbstractVehicle.h"

class ConcreteVehicle : public AbstractVehicle {
public:
    ConcreteVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1, uint8_t rightPin2,
                    uint8_t rightPinEna);

    void update() override;

    void configurate(Command **commands) override;

private:
    TenChangeCom left;
    TenChangeCom right;
    TenChangeCom forward;
    TenChangeCom backward;
    MotorActivateCom motorActivateCom;
    TenDampCom tenDampCom;
};


#endif //ROBOT_Z_CONCRETEVEHICLE_H
