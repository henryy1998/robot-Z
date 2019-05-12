//
// Created by fulva on 4/25/19.
//

#include <HardwareSerial.h>
#include "ServoControllCom.h"

//#define DEBUG
void ServoControllCom::execute(const int16_t *params) {
    servoFront.setDest(static_cast<uint8_t>(params[0]));
#ifdef DEBUG
    Serial.print("servo to:");
    Serial.println(params[0]);
#endif
}

ServoControllCom::ServoControllCom(CommandRegistry ident, ServoFront &servoFront)
        : VehicleCommand(
        ident), servoFront(servoFront) {}
