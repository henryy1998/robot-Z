//
// Created by fulva on 4/12/19.
//

#include "Command.h"


const String &Command::toString() {
    return identifier;
}

Command::Command(const String &identifier) : identifier(identifier) {

}
