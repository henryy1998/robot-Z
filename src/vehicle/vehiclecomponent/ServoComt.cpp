//
// Created by fulva on 4/28/19.
//

#include "ServoComt.h"

ServoComt::ServoComt(const String &servoComIdent, uint8_t pin) : servoCom(servoComIdent, servo) {
    servo.attach(pin);
    attachCommand(servoCom);
}
