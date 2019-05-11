//
// Created by Fulva on 4/27/2019.
//

#ifndef ROBOT_Z_STEPPERST_H
#define ROBOT_Z_STEPPERST_H


#include <behavior/VehicleCommand.h>
#include <mechanism/StepperFront.h>

class StepperST : public VehicleCommand {
public:
    StepperST(CommandRegistry ident, StepperFront &stepper, double multi);

private:
    StepperFront& stepper;
    double multi;

    void execute(const int16_t *params) override;

};


#endif //ROBOT_Z_STEPPERST_H
