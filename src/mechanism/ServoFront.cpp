//
// Created by fulva on 5/8/19.
//

#include <stdlib.h>
#include <HID.h>
#include "ServoFront.h"

#define DEBUG

#define TOLERANCE 3
#define SPEED 40

ServoFront::ServoFront(uint8_t pin, uint16_t minPulse = MIN_PULSE_WIDTH,
                       uint16_t maxPulse = MAX_PULSE_WIDTH) : pin(pin), mini(minPulse), maxi(maxPulse) {}

void ServoFront::activate() {
    const int currentPos = servo.read();
    Serial.print("servo location is:");
    Serial.println(currentPos);
    Serial.print("servo destAngle is:");
    Serial.println(destAngle);
    int distance = destAngle - currentPos;
    if (abs(distance) > TOLERANCE) {
        if (arrival) {
            arrival = false;
            lastTimeAc = millis();
        } else {
            if (!servo.attached()) {
                servo.attach(pin, mini, maxi);
            }
            const unsigned long currentTime = millis();
            int step = SPEED * (currentTime - lastTimeAc) / 1000 * (distance > 0 ? 1 : -1);
            if (abs(step) > abs(distance)) {
                step = distance;
            }
            if (step != 0) {
                lastTimeAc = currentTime;
                Serial.print("servo go to :");
                Serial.println(currentPos + step);
                servo.write(currentPos + step);
            }
        }
    } else {
        if (servo.attached()) {
            servo.detach();
        }
        if (!arrival) { arrival = true; }
#ifdef DEBUG
        Serial.println("detached");
        Serial.println();
#endif

    }
}


void ServoFront::setDest(uint8_t destAngle) {
    this->destAngle = destAngle;
}

const Servo &ServoFront::getServo() {
    return servo;
}

ServoFront::ServoFront(uint8_t
                       pin) : pin(pin), mini(MIN_PULSE_WIDTH), maxi(MAX_PULSE_WIDTH) {
}
