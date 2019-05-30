//
// Created by fulva on 5/30/19.
//

#ifndef ROBOT_Z_IRSENSOR_H
#define ROBOT_Z_IRSENSOR_H

#include <stdint-gcc.h>
#include "Sensor.h"

class IRSensor : public Sensor<bool> {
public:
    IRSensor(uint8_t sensorPin);

    bool getImform() override;

private:
    uint8_t pin;
};


#endif //ROBOT_Z_IRSENSOR_H
