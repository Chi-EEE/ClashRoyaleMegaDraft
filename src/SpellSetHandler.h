#ifndef SPELLSETHANDLER_H
#define SPELLSETHANDLER_H

#pragma once

#include <map>
#include <fstream>
#include <string>

#include "Global.h"
#include "SpellSet.h"

class SpellSetHandler
{
public:
	SpellSetHandler();
	SpellSetHandler(SpellSetHandler const&) = delete;
	SpellSetHandler& operator=(SpellSetHandler const&) = delete;

	std::shared_ptr<SpellSet> getSpellSet(std::string name) { spellSets[name]->shuffle(); return spellSets[name]; }

	static SpellSetHandler& getInstance() {
		static SpellSetHandler instance;
		return instance;
	}
private:
	void addSpellSets(std::ifstream& spellSetsCSV, std::shared_ptr<SpellSet> spellSet);
	std::map<std::string, std::shared_ptr<SpellSet>> spellSets;
};

#endif