//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_TENCHANGECOM_H
#define ROBOT_Z_TENCHANGECOM_H


#include <behavior/VehicleCommand.h>

class TenChangeCom : public VehicleCommand {
public:
//     TODO change string identifier type to const lvalue reference
    TenChangeCom(AbstractVehicle &vehicle, const String &identifier, uint8_t &ten);

private:
    uint8_t &ten;

    void execute(AbstractVehicle &vehicle, const String params[5]) override;

};


#endif //ROBOT_Z_TENCHANGECOM_H
