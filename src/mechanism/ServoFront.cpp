//
// Created by fulva on 5/8/19.
//

#include <stdlib.h>
#include <HID.h>
#include "ServoFront.h"

//#define DEBUG

#define TOLERANCE 3
#define SPEED 40
#define DISTANCE_FACTOR 1
#define STEP 2

ServoFront::ServoFront(uint8_t defalutAngle, uint8_t pin, uint16_t minPulse = MIN_PULSE_WIDTH,
                       uint16_t maxPulse = MAX_PULSE_WIDTH) : pin(pin), mini(minPulse), maxi(maxPulse) {
    servo.attach(pin);
    servo.write(defalutAngle);
}

void ServoFront::activate() {
#ifdef DEBUG
    Serial.print("servo location is:");
    Serial.println(currentPos);
    Serial.print("servo destAngle is:");
    Serial.println(destAngle);
#endif
    int distance = destAngle - currentPos;
    if (abs(distance) > TOLERANCE) {
        servo.attach(pin);
        while (abs(distance) > TOLERANCE) {
            currentPos = servo.read();
            servo.write(distance > 0 ? STEP + currentPos : -STEP + currentPos);
            delay(10);
            currentPos = servo.read();
            distance = destAngle - currentPos;
        }
        servo.detach();
    }
}


void ServoFront::setDest(uint8_t destAngle) {
    this->destAngle = destAngle;
}

const Servo &ServoFront::getServo() {
    return servo;
}

ServoFront::ServoFront(uint8_t pin, uint8_t defalutAngle) : ServoFront(
        defalutAngle, pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH) {

}
