//
// Created by fulva on 5/30/19.
//

#include "AlongRoute.h"

AlongRoute::AlongRoute(Sensor<bool> *left, Sensor<bool> *right, Sensor<bool> *middle, Sensor<int> *avoidObs,
                       Vehicle *vehicle)
        : left(left), right(right), middle(middle), avoidObs(avoidObs), vehicle(vehicle) {}
