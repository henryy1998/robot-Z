//
// Created by Fulva on 4/27/2019.
//

#ifndef ROBOT_Z_STEPPERFRONT_H
#define ROBOT_Z_STEPPERFRONT_H


#include <Stepper.h>

class StepperFront {
public:
    explicit StepperFront(Stepper stepper);

public:
    void setTarget(int16_t target);
    void activate();

    void setSpeed(long speed);

    Stepper &getStepper();
private:
    Stepper stepper;
    int16_t curPos;
    int16_t target;

};


#endif //ROBOT_Z_STEPPERFRONT_H
