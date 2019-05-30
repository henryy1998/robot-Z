//
// Created by fulva on 5/30/19.
//

#include "UltrasonicSensor.h"


int UltrasonicSensor::getImform() {
    return sensor.ping_cm();
}
