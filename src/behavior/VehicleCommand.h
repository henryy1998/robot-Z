//
// Created by fulva on 4/12/19.
//

#ifndef ROBOT_Z_VEHICLECOMMAND_H
#define ROBOT_Z_VEHICLECOMMAND_H


#include "vehicle/AbstractVehicle.h"

class VehicleCommand : public Command {
public:
    VehicleCommand(AbstractVehicle &vehicle, const String &identifier) : vehicle(vehicle), Command(identifier) {
    }

    void execute() override;

private:
    virtual void execute(AbstractVehicle &vehicle) = 0;

    AbstractVehicle &vehicle;

};


#endif //ROBOT_Z_VEHICLECOMMAND_H
