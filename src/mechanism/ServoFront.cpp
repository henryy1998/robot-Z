//
// Created by fulva on 5/8/19.
//

#include "ServoFront.h"

ServoFront::ServoFront(uint8_t pin, uint16_t minPulse = MIN_PULSE_WIDTH,
                       uint16_t maxPulse = MAX_PULSE_WIDTH) { servo.attach(pin, minPulse, maxPulse); }

void ServoFront::activate() {
    servo.write(destAngle);
}

void ServoFront::setDest(uint8_t destAngle) {
    this->destAngle = destAngle;
}

const Servo &ServoFront::getServo() {
    return servo;
}

ServoFront::ServoFront(uint8_t pin) {
    servo.attach(pin);

}
