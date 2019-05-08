//
// Created by fulva on 5/8/19.
//

#include "ServoAc.h"

ServoAc::ServoAc(const String &identifier, ServoFront &servoFront) : VehicleCommand(identifier),
                                                                     servoFront(servoFront) {}

void ServoAc::execute(const int16_t *params) {
    servoFront.activate();
}
