//
// Created by fulva on 4/25/19.
//

#include "ServoControllCom.h"

void ServoControllCom::execute(const int16_t *params) {
    servo.write(params[0]);
    Serial.print("servo to:");
    Serial.println(params[0]);
}

ServoControllCom::ServoControllCom(const String &identifier, Servo &servo)
        : VehicleCommand(
        identifier), servo(servo) {}
