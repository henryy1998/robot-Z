//
// Created by fulva on 5/8/19.
//

#include "ServoAc.h"

ServoAc::ServoAc(CommandRegistry ident, ServoFront &servoFront) : VehicleCommand(ident),
                                                                  servoFront(servoFront) {}

void ServoAc::execute(const int16_t *params) {
    servoFront.activate();
}
