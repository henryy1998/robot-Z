//
// Created by fulva on 4/28/19.
//

#ifndef ROBOT_Z_VEHICLECOMT_H
#define ROBOT_Z_VEHICLECOMT_H


#include <WString.h>
#include <behavior/VehicleCommand.h>

class VehicleComt {
public:
    VehicleComt();

    template<class T>
    void command(T identifier, const int16_t *params) {
        for (uint8_t i(0); i < index; i++) {
            if (commands[i]->getIdent() == identifier) {
                commands[i]->execute(params);
            }
        }
    }

protected:
    void attachCommand(VehicleCommand &vehicleCommand);

private:
    uint8_t index{0};
    VehicleCommand *commands[5];
};


#endif //ROBOT_Z_VEHICLECOMT_H
