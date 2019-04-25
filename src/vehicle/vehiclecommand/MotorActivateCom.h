//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_MOTORACTIVATECOM_H
#define ROBOT_Z_MOTORACTIVATECOM_H


#include <behavior/VehicleCommand.h>

class MotorActivateCom : public VehicleCommand {
public:
    MotorActivateCom(AbstractVehicle &vehicle, const String &identifier, Motor &motor, const int16_t &target,
                     int16_t &cSpeed);

private:
    void execute(AbstractVehicle &vehicle, const int16_t *params) override;

    Motor &motor;
    const int16_t &target;
    int16_t &cSpeed;
};


#endif //ROBOT_Z_MOTORACTIVATECOM_H
