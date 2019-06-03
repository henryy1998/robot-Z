//
// Created by fulva on 6/3/19.
//

#ifndef ROBOT_Z_AVOIDOBSRULE_H
#define ROBOT_Z_AVOIDOBSRULE_H


#include <mechanism/ServoFront.h>
#include <sensor/Sensor.h>
#include "Rule.h"

class AvoidObsRule : public Rule {
public:
    AvoidObsRule(Sensor<int> *sensor);

    void execute(Vehicle &vehicle) override;

private:
    uint8_t pos[3] = {0, 90, 180};
    Sensor<int> *sensor;
};


#endif //ROBOT_Z_AVOIDOBSRULE_H
