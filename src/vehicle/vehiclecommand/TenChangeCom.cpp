//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(AbstractVehicle &vehicle, const String &identifier, int16_t &ten) : VehicleCommand(vehicle,
                                                                                                              identifier),
                                                                                               ten(ten) {}

void TenChangeCom::execute(AbstractVehicle &vehicle, const int16_t *params) {
#ifdef DEBUG
    Serial.print("params[0]:");
    Serial.println(params[0]);
#endif
    ten = params[0];
}
