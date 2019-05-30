//
// Created by fulva on 5/30/19.
//

#include <HID.h>
#include "IRSensor.h"


IRSensor::IRSensor(uint8_t sensorPin) : pin(sensorPin) {

}

bool IRSensor::getImform() {
    return digitalRead(pin) == HIGH;
}
