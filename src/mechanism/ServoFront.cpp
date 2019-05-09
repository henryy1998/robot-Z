//
// Created by fulva on 5/8/19.
//

#include <stdlib.h>
#include <HID.h>
#include "ServoFront.h"

#define TOLERANCE 10
#define SPEED 20

ServoFront::ServoFront(uint8_t pin, uint16_t minPulse = MIN_PULSE_WIDTH,
                       uint16_t maxPulse = MAX_PULSE_WIDTH) { servo.attach(pin, minPulse, maxPulse); }

void ServoFront::activate() {
    const int currentPos = servo.read();
    Serial.print("servo location is:");
    Serial.println(currentPos);
    Serial.print("servo destAngle is:");
    Serial.println(destAngle);
    int distance = destAngle - currentPos;
    if (abs(distance) > TOLERANCE) {
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
}

void ServoFront::setDest(uint8_t destAngle) {
    Serial.print("set destAngle to:");
    Serial.println(destAngle);
    this->destAngle = destAngle;
}

const Servo &ServoFront::getServo() {
    return servo;
}

ServoFront::ServoFront(uint8_t
                       pin) {
    servo.attach(pin);

}
