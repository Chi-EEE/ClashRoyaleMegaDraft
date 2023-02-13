#include "SpellSetHandler.h"
#include<iostream>
std::shared_ptr<SpellSetHandler> SpellSetHandler::instance = std::make_shared<SpellSetHandler>(); // This line is broken

SpellSetHandler::SpellSetHandler()
{
	if (Global::fileExists("assets/spell_sets.csv")) {
		std::string _;
		std::ifstream spellSetsCSV("assets/spell_sets.csv");
		std::getline(spellSetsCSV, _); // Skip Headers
		std::getline(spellSetsCSV, _); // Skip Type Headers
		SpellSetHandler::addSpellSets(spellSetsCSV, nullptr);
		spellSetsCSV.close();
	}
	else {
		std::cout << "Unable to find spell_sets.csv";
	}
}

void SpellSetHandler::addSpellSets(std::ifstream& spellSetsCSV, std::shared_ptr<SpellSet> spellSet) {
	do {
		char character = spellSetsCSV.get();
		std::string spellSetName;
		while (character != ',') {
			spellSetName += character;
			character = spellSetsCSV.get();
		}
		if (spellSetName != "") {
			spellSets.insert(std::make_pair(spellSet->getName(), std::move(spellSet)));
			spellSet = std::make_shared<SpellSet>(spellSetName);
		}
		character = spellSetsCSV.get();
		std::string spellName;
		while (character != ',') {
			spellName += character;
			character = spellSetsCSV.get();
		}
		character = spellSetsCSV.get();
		std::string TID;
		while (character != '\n') {
			TID += character;
			character = spellSetsCSV.get();
		}
		spellSet->addSpell(std::make_shared<Spell>(spellSetName, TID));
	} while (Global::endOfFile(spellSetsCSV));
	spellSets.insert(std::make_pair(spellSet->getName(), std::move(spellSet)));
}