//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_VEHICLECOMT_H
#define ROBOT_Z_VEHICLECOMT_H


#include <WString.h>
#include <behavior/VehicleCommand.h>

class VehicleComt {
public:
    void command(const String &identifier, const int16_t params[5]);

    void attachCommand(VehicleCommand &vehicleCommand);

private:
    uint8_t index;
    VehicleCommand *commands[5];
};


#endif //ROBOT_Z_VEHICLECOMT_H
