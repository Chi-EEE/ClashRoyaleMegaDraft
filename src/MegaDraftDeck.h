#ifndef MegaDraftDeck_H
#define MegaDraftDeck_H

#pragma once

#include <array>

#include "Spell.h"

class MegaDraftDeck
{
public:
    MegaDraftDeck();
    ~MegaDraftDeck();

private:
    std::array<Spell, 36> spells;
};

#endif