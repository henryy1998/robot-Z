//
// Created by fulva on 5/8/19.
//

#ifndef ROBOT_Z_SERVOAC_H
#define ROBOT_Z_SERVOAC_H


#include <behavior/VehicleCommand.h>
#include <mechanism/ServoFront.h>

class ServoAc : public VehicleCommand {
public:
    ServoAc(CommandRegistry ident, ServoFront &servoFront);

    void execute(const int16_t *params) override;

private:
    ServoFront &servoFront;

};


#endif //ROBOT_Z_SERVOAC_H
