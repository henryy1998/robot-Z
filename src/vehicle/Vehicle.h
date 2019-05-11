//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_VEHICLE_H
#define ROBOT_Z_VEHICLE_H


#include "vehiclecomponent/VehicleComt.h"

class Vehicle {
public:
    Vehicle();

    void attachVehicleComt(VehicleComt &vehicleComt);

    void command(CommandRegistry identifier, const int16_t params[5]);

private:
    uint8_t index{0};
    VehicleComt *vehicleComts[10];

};


#endif //ROBOT_Z_VEHICLE_H
