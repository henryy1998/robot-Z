//
// Created by fulva on 4/28/19.
//

#include "MotorCom.h"

MotorCom::MotorCom(uint8_t pin1, uint8_t pin2, uint8_t pinEna, const String &acIdent, const String &tenChaIdent)
        : motor(pinEna, pin1, pin2), cSpeed(0), ten(0),
          motorA(acIdent, motor, ten, cSpeed), tenChangeCom(tenChaIdent, ten) {
    attachCommand(motorA);
    attachCommand(tenChangeCom);
}
