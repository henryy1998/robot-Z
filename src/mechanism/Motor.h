//
// Created by Fulva on 3/15/2019.
//

#ifndef ARDUINOSAMPLE_MOTOR_H
#define ARDUINOSAMPLE_MOTOR_H


#include <USBAPI.h>

class Motor {
public:
    Motor(uint8_t pin_ena, uint8_t pin_1, uint8_t pin_2);

    void drive(int16_t speed);

private:
    uint8_t pin_ena;
    uint8_t pin_1;
    uint8_t pin_2;
};


#endif //ARDUINOSAMPLE_MOTOR_H
