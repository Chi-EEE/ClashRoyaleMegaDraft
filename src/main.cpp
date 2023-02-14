#include <iostream>
#include <fstream>
#include <string>

#include "SpellSetHandler.h"
#include "MegaDraftDeck.h"

int main(int argc, char** argv)
{
    SpellSetHandler& spellSetHandler = SpellSetHandler::getInstance();
    auto megaDraftDeck = MegaDraftDeck();
    return 0;
}
