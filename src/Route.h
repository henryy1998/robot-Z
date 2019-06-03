//
// Created by fulva on 5/30/19.
//

#ifndef ROBOT_Z_ROUTE_H
#define ROBOT_Z_ROUTE_H


#include <mechanism/Motor.h>
#include <sensor/Sensor.h>
#include <vehicle/Vehicle.h>
#include <rules/Rule.h>
#include <sensor/IRSensor.h>
#include <sensor/UltrasonicSensor.h>
#include "vehicle/vehiclecomponent/VehicleComt.h"

class Route {
public:
    Route(Vehicle *vehicle);

private:
    Rule *rules[10];
    IRSensor left;
    IRSensor right;
    IRSensor middle;
    UltrasonicSensor ultrasonicSensor;
    Vehicle &vehicle;


};


#endif //ROBOT_Z_ROUTE_H
