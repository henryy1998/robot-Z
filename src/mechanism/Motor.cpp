//
// Created by Fulva on 3/15/2019.
//

#include "Motor.h"

Motor::Motor(uint8_t pin_ena, uint8_t pin_1, uint8_t pin_2) :
        pin_ena(pin_ena),
        pin_1(pin_1),
        pin_2(pin_2) {
    pinMode(pin_1, OUTPUT);
    pinMode(pin_2, OUTPUT);
    pinMode(pin_ena, OUTPUT);
}

void Motor::drive(int16_t speed) {
    if (speed >= 0) {
        digitalWrite(pin_1, HIGH);
        digitalWrite(pin_2, LOW);
    } else {
        speed = abs(speed);
        digitalWrite(pin_1, LOW);
        digitalWrite(pin_2, HIGH);
    }
    if (speed > UINT8_MAX) {
        speed = UINT8_MAX;
    }
    analogWrite(pin_ena, abs(speed));
}
