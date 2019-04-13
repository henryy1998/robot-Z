//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(Vehicle &vehicle, String &&identifier, uint8_t &ten) : VehicleCommand(vehicle, identifier),
                                                                                  ten(ten) {}

void TenChangeCom::execute(Vehicle &vehicle) {
    ten = UINT8_MAX;
}
