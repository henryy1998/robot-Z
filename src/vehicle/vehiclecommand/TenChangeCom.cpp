//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(AbstractVehicle &vehicle, String &&identifier, uint8_t &ten) : VehicleCommand(vehicle,
                                                                                                         identifier),
                                                                                          ten(ten) {}

void TenChangeCom::execute(AbstractVehicle &vehicle) {
    ten = min(ten + 20, UINT8_MAX);
}
