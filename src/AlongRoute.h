//
// Created by fulva on 5/30/19.
//

#ifndef ROBOT_Z_ALONGROUTE_H
#define ROBOT_Z_ALONGROUTE_H


#include <mechanism/Motor.h>
#include <sensor/Sensor.h>
#include <vehicle/Vehicle.h>
#include "vehicle/vehiclecomponent/VehicleComt.h"

class AlongRoute {
public:
    AlongRoute(Sensor<bool> *left, Sensor<bool> *right, Sensor<bool> *middle, Sensor<int> *avoidObs,
               Vehicle *vehicle);

private:
    Sensor<bool> *left;
    Sensor<bool> *right;
    Sensor<bool> *middle;
    Sensor<int> *avoidObs;
    Vehicle *vehicle;


};


#endif //ROBOT_Z_ALONGROUTE_H
