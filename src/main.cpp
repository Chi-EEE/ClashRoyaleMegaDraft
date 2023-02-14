#include <iostream>
#include <fstream>
#include <string>

#include "SpellSetHandler.h"

int main(int argc, char** argv)
{
    SpellSetHandler& spellSetHandler = SpellSetHandler::getInstance();
    auto spellSet = spellSetHandler.getSpellSet("SetRandomRangedSupport");
    spellSet->shuffle();
    return 0;
}
