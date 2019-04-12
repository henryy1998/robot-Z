#include <utility>

//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLECOMMAND_H
#define ROBOT_Z_VEHICLECOMMAND_H


#include "Vehicle.h"

class VehicleCommand : public Command {
public:
    VehicleCommand(Vehicle &vehicle, String &&identifier) : vehicle(vehicle), Command(identifier) {
    };

private:
    Vehicle &vehicle;

};


#endif //ROBOT_Z_VEHICLECOMMAND_H
