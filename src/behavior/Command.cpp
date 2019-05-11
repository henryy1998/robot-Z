//
// Created by fulva on 4/12/19.
//

#include "Command.h"


const CommandRegistry Command::getIdent() {
    return identifier;
}

Command::Command(CommandRegistry ident) : identifier(ident) {

}
