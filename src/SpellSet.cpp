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

void SpellSet::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	std::shuffle(spells.begin(), spells.end(), e);
}