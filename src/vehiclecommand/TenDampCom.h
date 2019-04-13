//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_TENDAMPCOM_H
#define ROBOT_Z_TENDAMPCOM_H


#include <VehicleCommand.h>

class TenDampCom : public VehicleCommand {
public:
    TenDampCom(Vehicle &vehicle, const String &identifier);

private:
    void execute(Vehicle &vehicle) override;
};


#endif //ROBOT_Z_TENDAMPCOM_H
