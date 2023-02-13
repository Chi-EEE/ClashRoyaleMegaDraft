#include "SpellSetHandler.h"

std::shared_ptr<SpellSetHandler> instance = std::make_unique<SpellSetHandler>();

SpellSetHandler::SpellSetHandler()
{
	std::string _;
	std::ifstream spellSetsCSV("assets/spell_sets.csv");
	std::getline(spellSetsCSV, _); // Skip Headers
	std::getline(spellSetsCSV, _); // Skip Type Headers
	SpellSetHandler::addSpellSets(spellSetsCSV, nullptr);
	spellSetsCSV.close();
}

SpellSetHandler::~SpellSetHandler()
{

}

void SpellSetHandler::addSpellSets(std::ifstream& spellSetsCSV, std::unique_ptr<SpellSet> spellSet) {
	do {
		char character = spellSetsCSV.get();
		std::string spellSetName;
		while (character != ',') {
			spellSetName += character;
			character = spellSetsCSV.get();
		}
		if (spellSetName != "") {
			spellSets.push_back(std::move(spellSet));
			spellSet = std::make_unique<SpellSet>(spellSetName);
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
	spellSets.push_back(std::move(spellSet));
}