#include "MegaDraftDeck.h"

MegaDraftDeck::MegaDraftDeck()
{
	spells.reserve(36);
	SpellSetHandler& spellSetHandler = SpellSetHandler::getInstance();
	auto Draft_RH_TankUnit = spellSetHandler.getSpellSet("Draft_RH_TankUnit");
	auto Draft_RH_AntiAir = spellSetHandler.getSpellSet("Draft_RH_AntiAir");
	auto Draft_RH_CycleUnder3 = spellSetHandler.getSpellSet("Draft_RH_CycleUnder3");
	auto Draft_RH_DirectDamage = spellSetHandler.getSpellSet("Draft_RH_DirectDamage");
	auto Draft_RH_WinCons = spellSetHandler.getSpellSet("Draft_RH_WinCons");
	auto Draft_RH_2ndSpell = spellSetHandler.getSpellSet("Draft_RH_2ndSpell");
	auto Draft_RH_MiniTank = spellSetHandler.getSpellSet("Draft_RH_MiniTank");
	auto Draft_RH_Champions = spellSetHandler.getSpellSet("Draft_RH_Champions");
	auto Draft_RH_Investment = spellSetHandler.getSpellSet("Draft_RH_Investment");
	addSpells(Draft_RH_TankUnit, 4);
	addSpells(Draft_RH_AntiAir, 4);
	addSpells(Draft_RH_CycleUnder3, 4);
	addSpells(Draft_RH_DirectDamage, 4);
	addSpells(Draft_RH_WinCons, 4);
	addSpells(Draft_RH_2ndSpell, 4);
	addSpells(Draft_RH_MiniTank, 4);
	addSpells(Draft_RH_Champions, 4);
	addSpells(Draft_RH_Investment, 4);
}

MegaDraftDeck::~MegaDraftDeck()
{

}

void MegaDraftDeck::addSpells(std::shared_ptr<SpellSet> spellSet, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		spells.push_back(spellSet->getSpell(i));
	}
}
