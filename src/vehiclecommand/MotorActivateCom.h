//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_MOTORACTIVATECOM_H
#define ROBOT_Z_MOTORACTIVATECOM_H


#include <VehicleCommand.h>

class MotorActivateCom : public VehicleCommand {
public:
    MotorActivateCom(Vehicle &vehicle, const String &identifier);

private:
    void execute(Vehicle &vehicle) override;
};


#endif //ROBOT_Z_MOTORACTIVATECOM_H
