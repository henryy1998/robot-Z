//
// Created by Fulva on 4/27/2019.
//

#ifndef ROBOT_Z_STEPPERFRONT_H
#define ROBOT_Z_STEPPERFRONT_H


#include <Stepper.h>
#include <AccelStepper.h>

class StepperFront {
public:
    explicit StepperFront(AccelStepper stepper);

public:
    void setTarget(int16_t target);
    void activate();

    void setSpeed(long speed);

    void setAccel(float accel);

    AccelStepper &getStepper();
private:
    AccelStepper stepper;

};


#endif //ROBOT_Z_STEPPERFRONT_H
