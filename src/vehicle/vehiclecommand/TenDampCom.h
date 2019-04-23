//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_TENDAMPCOM_H
#define ROBOT_Z_TENDAMPCOM_H


#include <behavior/VehicleCommand.h>

class TenDampCom : public VehicleCommand {
public:
    TenDampCom(AbstractVehicle &vehicle, const String &identifier);

private:
    void execute(AbstractVehicle &vehicle, const int16_t *params) override;
};


#endif //ROBOT_Z_TENDAMPCOM_H
