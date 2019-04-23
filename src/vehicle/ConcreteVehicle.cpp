//
// Created by fulva on 4/13/19.
//

#include "ConcreteVehicle.h"

ConcreteVehicle::ConcreteVehicle(uint8_t leftPin1, uint8_t leftPin2, uint8_t leftPinEna, uint8_t rightPin1,
                                 uint8_t rightPin2, uint8_t rightPinEna) :
        AbstractVehicle(leftPin1, leftPin2,
                        leftPinEna, rightPin1,
                        rightPin2, rightPinEna),
        left(*this, "left", this->getLeftTen()),
        right(*this, "right", this->getRightTen()),
        forward(*this, "forward", this->getForwardTen()),
        backward(*this, "backward", this->getBackwardTen()),
        motorActivateCom(*this, "motor roll"),
        tenDampCom(*this, "ten damping") {
    Command **const commands = getCommands();
    commands[0] = &left;
    commands[1] = &right;
    commands[2] = &forward;
    commands[3] = &backward;
}

void ConcreteVehicle::update() {
    dynamic_cast<VehicleCommand &>(motorActivateCom).execute(nullptr);
    dynamic_cast<VehicleCommand &>(tenDampCom).execute(nullptr);

}
