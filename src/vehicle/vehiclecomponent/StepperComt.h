//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_STEPPERCOMT_H
#define ROBOT_Z_STEPPERCOMT_H


#include <vehicle/vehiclecommand/StepperAc.h>
#include <vehicle/vehiclecommand/StepperST.h>
#include "VehicleComt.h"

class StepperComt : public VehicleComt {
public:
    StepperComt(uint16_t stepNumber, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, const String &acIdent,
                const String &stIdent, uint8_t multi, long speed);

private:
    StepperFront stepper;
    StepperAc stepperAc;
    StepperST stepperSt;
};


#endif //ROBOT_Z_STEPPERCOMT_H
