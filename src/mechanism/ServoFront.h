//
// Created by fulva on 5/8/19.
//

#ifndef ROBOT_Z_SERVOFRONT_H
#define ROBOT_Z_SERVOFRONT_H


#include <Servo.h>

class ServoFront {
public:
    ServoFront(uint8_t pin, uint16_t minPulse, uint16_t maxPulse);

    ServoFront(uint8_t pin);

    void activate();

    void setDest(uint8_t destAngle);

    const Servo &getServo();

private:
    const uint8_t pin;
    const uint16_t mini;
    const uint16_t maxi;
    Servo servo;
    uint8_t destAngle{90};
    unsigned long lastTimeAc{0};

};


#endif //ROBOT_Z_SERVOFRONT_H
