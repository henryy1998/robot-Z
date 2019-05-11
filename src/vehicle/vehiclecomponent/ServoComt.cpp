//
// Created by fulva on 4/28/19.
//

#include "ServoComt.h"

ServoComt::ServoComt(const String &servoComIdent, const String &servoAcIdent, uint8_t pin, uint8_t defaultAngle)
        : servoCom(servoComIdent,
                   servoFront),
          servoAc(servoAcIdent,
                  servoFront),
          servoFront(pin, defaultAngle) {
    attachCommand(servoCom);
    attachCommand(servoAc);
}
