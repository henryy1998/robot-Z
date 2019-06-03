//
// Created by fulva on 6/3/19.
//

#ifndef ROBOT_Z_RULE_H
#define ROBOT_Z_RULE_H


#include <vehicle/Vehicle.h>

class Rule {
public:
    virtual void execute(Vehicle &vehicle) = 0;

};


#endif //ROBOT_Z_RULE_H
