//
// Created by fulva on 4/25/19.
//

#ifndef ROBOT_Z_SERVOCONTROLLCOM_H
#define ROBOT_Z_SERVOCONTROLLCOM_H


#include <mechanism/ServoFront.h>
#include <behavior/VehicleCommand.h>

class ServoControllCom : public VehicleCommand {
public:
    ServoControllCom(const String &identifier, ServoFront &servoFront);

private:
    void execute(const int16_t *params) override;

    ServoFront &servoFront;
};


#endif //ROBOT_Z_SERVOCONTROLLCOM_H
