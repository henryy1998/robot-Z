//
// Created by Fulva on 4/27/2019.
//

#ifndef ROBOT_Z_STEPPERST_H
#define ROBOT_Z_STEPPERST_H


#include <behavior/VehicleCommand.h>

class StepperST : public VehicleCommand {
public:
    StepperST(const String &identifier, StepperFront &stepper, double multi);

private:
    StepperFront& stepper;
    double multi;

    void execute(const int16_t *params) override;

};


#endif //ROBOT_Z_STEPPERST_H
