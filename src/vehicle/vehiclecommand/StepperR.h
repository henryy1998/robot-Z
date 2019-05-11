//
// Created by fulva on 5/2/19.
//

#ifndef ROBOT_Z_STEPPERR_H
#define ROBOT_Z_STEPPERR_H


#include <behavior/VehicleCommand.h>

class StepperR : public VehicleCommand {
public:
    StepperR(CommandRegistry ident, StepperFront &stepper);

    void execute(const int16_t *params) override;

private:
    StepperFront &stepper;

};


#endif //ROBOT_Z_STEPPERR_H
