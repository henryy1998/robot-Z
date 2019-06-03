//
// Created by fulva on 6/3/19.
//

#ifndef ROBOT_Z_IRRULE_H
#define ROBOT_Z_IRRULE_H


#include <sensor/Sensor.h>
#include "Rule.h"

class IRrule : public Rule {
public:
    IRrule(Sensor<bool> *sensor, CommandRegistry command, int16_t param);

    void execute(Vehicle &vehicle) override;

private:
    Sensor<bool> *sensor;
    CommandRegistry command;
    int16_t param;

};


#endif //ROBOT_Z_IRRULE_H
