//
// Created by fulva on 5/8/19.
//

#include "BufferDecor.h"

BufferDecor::BufferDecor(VehicleCommand &decorant, uint16_t bufferTime) : VehicleCommand(
        decorant.getIdent()), decorant(decorant), bufferTime(bufferTime) {}

void BufferDecor::execute(const int16_t *params) {
    unsigned long curTime;
    if (curTime - lastTimeExecute > bufferTime) {
        lastTimeExecute = curTime;

    }
}
