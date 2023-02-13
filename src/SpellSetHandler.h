#ifndef SPELLSETHANDLER_H
#define SPELLSETHANDLER_H

#pragma once

#include <vector>
#include <fstream>
#include <string>

#include "Global.h"
#include "SpellSet.h"

class SpellSetHandler
{
public:
	std::shared_ptr<SpellSetHandler> getInstance() { return instance; }
private:
	SpellSetHandler();
	~SpellSetHandler();
	static std::shared_ptr<SpellSetHandler> instance;
	void addSpellSets(std::ifstream& spellSetsCSV, std::unique_ptr<SpellSet> spellSet);
	std::vector<std::unique_ptr<SpellSet>> spellSets;
};

#endif