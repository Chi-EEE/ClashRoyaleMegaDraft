#ifndef SPELLSET_H
#define SPELLSET_H

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Spell.h"

class SpellSet {
public:
	SpellSet(std::string name);
	~SpellSet();
	void addSpell(std::shared_ptr<Spell> spell);
private:
	std::string name;
	std::vector<std::shared_ptr<Spell>> spells;
};
#endif