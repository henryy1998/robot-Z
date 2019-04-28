//
// Created by fulva on 4/25/19.
//

#ifndef ROBOT_Z_SERVOCONTROLLCOM_H
#define ROBOT_Z_SERVOCONTROLLCOM_H


#include "../../behavior/VehicleCommand.h"
#include "../AbstractVehicle.h"

class ServoControllCom : public VehicleCommand {
public:
    ServoControllCom(AbstractVehicle &vehicle, const String &identifier, Servo &servo);

private:
    virtual void execute(const int16_t *params);

    Servo &servo;
};


#endif //ROBOT_Z_SERVOCONTROLLCOM_H
