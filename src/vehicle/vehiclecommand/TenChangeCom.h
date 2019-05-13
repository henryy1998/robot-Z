//
// Created by fulva on 4/13/19.
//

#ifndef ROBOT_Z_TENCHANGECOM_H
#define ROBOT_Z_TENCHANGECOM_H


#include <behavior/VehicleCommand.h>

class TenChangeCom : public VehicleCommand {
public:
    template<class T>
    TenChangeCom(T ident, int16_t &ten) : VehicleCommand(ident),
                                          ten(ten) {}

private:
    int16_t &ten;

    void execute(const int16_t *params) override;

};


#endif //ROBOT_Z_TENCHANGECOM_H
