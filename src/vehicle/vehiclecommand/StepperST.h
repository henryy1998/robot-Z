//
// Created by Fulva on 4/27/2019.
//

#ifndef ROBOT_Z_STEPPERST_H
#define ROBOT_Z_STEPPERST_H


#include <behavior/VehicleCommand.h>

class StepperST : public VehicleCommand {
public:
    StepperST(AbstractVehicle &vehicle, const String &identifier, StepperFront &stepper);

private:
    StepperFront& stepper;
    void execute(AbstractVehicle &vehicle, const int16_t *params) override;

};


#endif //ROBOT_Z_STEPPERST_H
