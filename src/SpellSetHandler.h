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
	static std::shared_ptr<SpellSetHandler> getInstance() { return instance; }
	std::shared_ptr<SpellSet> getSpellSet(std::string name) { return spellSets[name]; }
	SpellSetHandler();
private:
	static std::shared_ptr<SpellSetHandler> instance;
	void addSpellSets(std::ifstream& spellSetsCSV, std::shared_ptr<SpellSet> spellSet);
	std::map<std::string, std::shared_ptr<SpellSet>> spellSets;
};

#endif