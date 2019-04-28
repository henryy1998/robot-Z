//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLECOMMAND_H
#define ROBOT_Z_VEHICLECOMMAND_H


#include "vehicle/AbstractVehicle.h"

class VehicleCommand : public Command {
public:
    VehicleCommand(const String &identifier) : Command(identifier) {
    }
};


#endif //ROBOT_Z_VEHICLECOMMAND_H
