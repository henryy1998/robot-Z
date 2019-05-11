//
// Created by fulva on 4/28/19.
//

#include "MotorComt.h"

MotorComt::MotorComt(uint8_t pin1, uint8_t pin2, uint8_t pinEna, CommandRegistry acIdent, CommandRegistry tenChaIdent)
        : motor(pinEna, pin1, pin2), cSpeed(0), ten(0),
          motorA(acIdent, motor, ten, cSpeed), tenChangeCom(tenChaIdent, ten) {
    attachCommand(motorA);
    attachCommand(tenChangeCom);
}
