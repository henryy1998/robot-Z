//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_MOTORCOM_H
#define ROBOT_Z_MOTORCOM_H


#include <vehicle/vehiclecommand/TenChangeCom.h>
#include "../../mechanism/Motor.h"
#include "VehicleComt.h"
#include <vehicle/vehiclecommand/MotorActivateCom.h>

class MotorCom : public VehicleComt {
public:
    MotorCom(uint8_t pin1, uint8_t pin2, uint8_t pinEna, const String &acIdent, const String &tenChaIdent);

private:
    Motor motor;
    MotorActivateCom motorA;
    TenChangeCom tenChangeCom;
    int16_t ten;
    int16_t cSpeed;

};


#endif //ROBOT_Z_MOTORCOM_H
