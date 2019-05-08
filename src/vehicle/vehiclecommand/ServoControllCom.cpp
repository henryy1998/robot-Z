//
// Created by fulva on 4/25/19.
//

#include "ServoControllCom.h"

void ServoControllCom::execute(const int16_t *params) {
    int angle(params[0]);
    servo.writeMicroseconds(map(angle, 0, 180, 500, 1500));
    Serial.print("servo to:");
    Serial.println(angle);
}

ServoControllCom::ServoControllCom(const String &identifier, Servo &servo)
        : VehicleCommand(
        identifier), servo(servo) {}
