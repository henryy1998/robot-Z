//
// Created by fulva on 5/2/19.
//

#include <mechanism/StepperFront.h>
#include "StepperR.h"


void StepperR::execute(const int16_t *params) {
    stepper.resetPos();
}
