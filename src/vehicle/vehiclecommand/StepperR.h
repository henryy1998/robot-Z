//
// Created by fulva on 5/2/19.
//

#ifndef ROBOT_Z_STEPPERR_H
#define ROBOT_Z_STEPPERR_H


#include <behavior/VehicleCommand.h>

class StepperR : public VehicleCommand {
public:
    template<class T>
    StepperR(T ident, StepperFront &stepper) : VehicleCommand(ident), stepper(stepper) {}

    void execute(const int16_t *params) override;

private:
    StepperFront &stepper;

};


#endif //ROBOT_Z_STEPPERR_H
