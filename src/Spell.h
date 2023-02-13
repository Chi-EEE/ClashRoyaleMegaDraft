#ifndef SPELL_H
#define SPELL_H

#pragma once

#include <string>
#include <vector>

class Spell {
public:
private:
	std::string name;
	std::string TID;
	std::vector<Spell> spells;
};
#endif
