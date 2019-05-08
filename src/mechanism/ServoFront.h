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
    Servo servo;
    uint16_t destAngle{0};

};


#endif //ROBOT_Z_SERVOFRONT_H
