//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_MOTORCOMT_H
#define ROBOT_Z_MOTORCOMT_H


#include <vehicle/vehiclecommand/TenChangeCom.h>
#include "../../mechanism/Motor.h"
#include "VehicleComt.h"
#include <vehicle/vehiclecommand/MotorActivateCom.h>

class MotorComt : public VehicleComt {
public:
    template<class T>
    MotorComt(uint8_t pin1, uint8_t pin2, uint8_t pinEna, T acIdent, T tenChaIdent)
            : motor(pinEna, pin1, pin2), cSpeed(0), ten(0),
              motorA(acIdent, motor, ten, cSpeed), tenChangeCom(tenChaIdent, ten) {
        attachCommand(motorA);
        attachCommand(tenChangeCom);
    }

private:
    Motor motor;
    MotorActivateCom motorA;
    TenChangeCom tenChangeCom;
    int16_t ten;
    int16_t cSpeed;

};


#endif //ROBOT_Z_MOTORCOMT_H
