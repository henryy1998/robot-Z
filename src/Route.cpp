//
// Created by fulva on 5/30/19.
//

#include <rules/IRrule.h>
#include "Route.h"
#include "PinConfig.h"


Route::Route(Vehicle *vehicle) :
        vehicle(*vehicle),
        left(LEFT_SENSOR_PIN),
        right(RIGHT_SENSOR_PIN),
        middle(MIDDLE_SENSOR_PIN),
        ultrasonicSensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN, 10) {
    rules[0] = new IRrule(&left, CommandRegistry::LEFT_MOTOR_SS, 255);
    rules[1] = new IRrule(&right, CommandRegistry::RIGHT_MOTOR_SS, 255);


}
