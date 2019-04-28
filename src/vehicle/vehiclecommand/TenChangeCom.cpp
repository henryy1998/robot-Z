//
// Created by fulva on 4/13/19.
//

#include "TenChangeCom.h"

TenChangeCom::TenChangeCom(const String &identifier, int16_t &ten) : VehicleCommand(
        identifier),
                                                                     ten(ten) {}

void TenChangeCom::execute(const int16_t *params) {
#ifdef DEBUG
    Serial.print("params[0]:");
    Serial.println(params[0]);
#endif
    ten = params[0];
}
