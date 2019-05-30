//
// Created by fulva on 5/30/19.
//

#ifndef ROBOT_Z_SENSOR_H
#define ROBOT_Z_SENSOR_H


template<class Return>
class Sensor {
public:
    virtual Return getImform() = 0;
};


#endif //ROBOT_Z_SENSOR_H
