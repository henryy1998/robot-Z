//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_SERVOCOMT_H
#define ROBOT_Z_SERVOCOMT_H


#include <vehicle/vehiclecommand/ServoControllCom.h>
#include "VehicleComt.h"

class ServoComt : public VehicleComt {
public:
    ServoComt(const String &servoComIdent, uint8_t pin);

private:
    Servo servo;
    ServoControllCom servoCom;
};


#endif //ROBOT_Z_SERVOCOMT_H
