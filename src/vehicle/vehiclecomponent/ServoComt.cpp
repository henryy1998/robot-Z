//
// Created by fulva on 4/28/19.
//

#include "ServoComt.h"

ServoComt::ServoComt(const String &servoComIdent, const String &servoAcIdent, uint8_t pin) : servoCom(servoComIdent,
                                                                                                      servoFront),
                                                                                             servoAc(servoAcIdent,
                                                                                                     servoFront),
                                                                                             servoFront(pin) {
    attachCommand(servoCom);
    attachCommand(servoAc);
}
