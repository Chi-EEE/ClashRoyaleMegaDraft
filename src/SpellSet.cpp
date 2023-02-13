#include "SpellSet.h"

SpellSet::SpellSet(std::string name): name(name)
{
}

SpellSet::~SpellSet()
{
}

void SpellSet::addSpell(std::shared_ptr<Spell> spell)
{
	spells.push_back(spell);
}
