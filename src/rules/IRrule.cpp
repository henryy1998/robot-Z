//
// Created by fulva on 6/3/19.
//

#include "IRrule.h"

void IRrule::execute(Vehicle &vehicle) {

}

IRrule::IRrule(Sensor<bool> *sensor, CommandRegistry command, int16_t param)
        : sensor(sensor), command(command), param(param) {}
