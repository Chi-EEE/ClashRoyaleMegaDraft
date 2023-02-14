#ifndef SPELLSET_H
#define SPELLSET_H

#pragma once

#include <string>
#include <vector>

#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <memory>
#include "Spell.h"

class SpellSet {
public:
	SpellSet(std::string name);
	~SpellSet();
	void addSpell(std::shared_ptr<Spell> spell);
	std::string getName() { return name; }
	void shuffle();
	operator std::string() const
	{
		std::string output = this->name + " : [";
		for (auto spell : this->spells) {
			output += spell->getName() + " ";
		}
		output += "]";
		return output;
	}
	std::shared_ptr<Spell> getSpell(int i) {
		return spells[i];
	}
private:
	std::string name;
	std::vector<std::shared_ptr<Spell>> spells;
};

#endif