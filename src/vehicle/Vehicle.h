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

    void command(const String &identifier, const int16_t params[5]);

private:
    uint8_t index;
    VehicleComt *vehicleComts[5];

};


#endif //ROBOT_Z_VEHICLE_H
