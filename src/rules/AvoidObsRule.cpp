//
// Created by fulva on 6/3/19.
//

#include "AvoidObsRule.h"

#define MIN_DIS 3

void AvoidObsRule::execute(Vehicle &vehicle) {
    int16_t params[1] = {pos[0]};
    vehicle.command(CommandRegistry::SERVO1SS, params);
    int leftdis = sensor->getImform();
    params[0] = pos[1];
    vehicle.command(CommandRegistry::SERVO1SS, params);
    int middledis = sensor->getImform();
    params[0] = pos[2];
    vehicle.command(CommandRegistry::SERVO1SS, params);
    int rightdis = sensor->getImform();
    if (middledis < MIN_DIS) {
        int16_t params2[1];
        params2[0] = 255;
        if (rightdis >= leftdis) {
            vehicle.command(CommandRegistry::LEFT_MOTOR_SS, params2);
        } else {
            vehicle.command(CommandRegistry::RIGHT_MOTOR_SS, params2);
        }
    }
}

AvoidObsRule::AvoidObsRule(Sensor<int> *sensor) : sensor(sensor) {}
