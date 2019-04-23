//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(AbstractVehicle &vehicle, const String &identifier, uint8_t &ten) : VehicleCommand(vehicle,
                                                                                                              identifier),
                                                                                               ten(ten) {}

void TenChangeCom::execute(AbstractVehicle &vehicle, const String params[5]) {
    ten = (uint8_t) params[0].toInt();
}
