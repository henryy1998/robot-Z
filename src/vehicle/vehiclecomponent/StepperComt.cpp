//
// Created by fulva on 4/28/19.
//

#include "StepperComt.h"

StepperComt::StepperComt(uint16_t stepNumber, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4,
                         const String &acIdent, const String &stIdent, uint8_t multi) : stepper(
        Stepper(stepNumber, pin1, pin2, pin3, pin4)),
                                                                                        stepperAc(acIdent, stepper),
                                                                                        stepperSt(stIdent, stepper,
                                                                                                  multi) {
    attachCommand(stepperAc);
    attachCommand(stepperSt);
}
