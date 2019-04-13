//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLECOMMAND_H
#define ROBOT_Z_VEHICLECOMMAND_H


#include "Vehicle.h"

class VehicleCommand : public Command {
public:
    VehicleCommand(Vehicle &vehicle, const String &identifier) : vehicle(vehicle), Command(identifier) {
    }

    void execute() override;

private:
    virtual void execute(Vehicle &vehicle) = 0;

    Vehicle &vehicle;

};


#endif //ROBOT_Z_VEHICLECOMMAND_H
