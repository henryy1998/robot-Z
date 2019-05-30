//
// Created by fulva on 5/30/19.
//

#ifndef ROBOT_Z_ULTRASONICSENSOR_H
#define ROBOT_Z_ULTRASONICSENSOR_H


#include "Sensor.h"
#include <NewPing.h>

class UltrasonicSensor : public Sensor<int> {
public:

    UltrasonicSensor(uint8_t triggerPin, uint8_t echoPin, unsigned int max_cm_distance) : sensor(triggerPin, echoPin,
                                                                                                 max_cm_distance) {}

    int getImform() override;

private:

    NewPing sensor;

};


#endif //ROBOT_Z_ULTRASONICSENSOR_H
