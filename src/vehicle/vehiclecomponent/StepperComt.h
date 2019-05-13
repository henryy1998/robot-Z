//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_STEPPERCOMT_H
#define ROBOT_Z_STEPPERCOMT_H


#include <vehicle/vehiclecommand/StepperAc.h>
#include <vehicle/vehiclecommand/StepperST.h>
#include <vehicle/vehiclecommand/StepperR.h>
#include "VehicleComt.h"

class StepperComt : public VehicleComt {
public:
    template<class T>
    StepperComt(uint16_t stepNumber, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4,
                T acIdent, T stIdent, T rIdent, double multi,
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

private:
    StepperFront stepper;
    StepperAc stepperAc;
    StepperST stepperSt;
    StepperR stepperR;
};


#endif //ROBOT_Z_STEPPERCOMT_H
