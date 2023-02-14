#ifndef MegaDraftDeck_H
#define MegaDraftDeck_H

#pragma once

#include <memory>
#include <vector>

#include "SpellSetHandler.h"
#include "SpellSet.h"
#include "Spell.h"

class MegaDraftDeck
{
public:
    MegaDraftDeck();
    ~MegaDraftDeck();

private:
    void addSpells(std::shared_ptr<SpellSet> spellSet, int amount);
    std::map<std::string, std::shared_ptr<Spell>> spells;
};

#endif