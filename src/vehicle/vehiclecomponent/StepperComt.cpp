//
// Created by fulva on 4/28/19.
//

#include "StepperComt.h"

StepperComt::StepperComt(uint16_t stepNumber, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4,
                         const String &acIdent, const String &stIdent, const String &rIdent, double multi,
                         long speed) : stepper(
        Stepper(stepNumber, pin1, pin2, pin3, pin4)),
                                       stepperAc(acIdent, stepper),
                                       stepperSt(stIdent, stepper,
                                                 multi),
                                       stepperR(rIdent, stepper) {
    attachCommand(stepperAc);
    attachCommand(stepperSt);
    attachCommand(stepperR);
    stepper.setSpeed(speed);
}
