//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(AbstractVehicle &vehicle, String &&identifier, uint8_t &ten) : VehicleCommand(vehicle,
                                                                                                         identifier),
                                                                                          ten(ten) {}

void TenChangeCom::execute(AbstractVehicle &vehicle) {
    ten = UINT8_MAX;
}
