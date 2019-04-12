//
// Created by fulva on 4/12/19.
//

#include "Command.h"


String Command::toString() {
    return String();
}

Command::Command(String &&identifier) : identifier(identifier) {

}
