//
// Created by fulva on 5/8/19.
//

#ifndef ROBOT_Z_BUFFERDECOR_H
#define ROBOT_Z_BUFFERDECOR_H


#include <behavior/VehicleCommand.h>

class BufferDecor : public VehicleCommand {
public:
    BufferDecor(VehicleCommand &decorant, uint16_t bufferTime);

    void execute(const int16_t *params) override;

public:
private:
    VehicleCommand &decorant;
    unsigned long lastTimeExecute{0};
    uint16_t bufferTime;

};


#endif //ROBOT_Z_BUFFERDECOR_H
