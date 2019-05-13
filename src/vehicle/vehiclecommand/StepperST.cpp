//
// Created by Fulva on 4/27/2019.
//

#include "StepperST.h"


void StepperST::execute(const int16_t *params) {
    stepper.setTarget((static_cast<int16_t>((params[0]) * multi)));
}
