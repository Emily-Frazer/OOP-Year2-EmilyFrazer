#include "CombatUnit.h"
#include <iostream>

CombatUnit::CombatUnit(int t_health)
{
	std::cout << "+ Combat Unit\n" ;
	m_health = t_health;
}

CombatUnit::~CombatUnit()
{
	std::cout << "- Combat Unit\n";
}

int CombatUnit::health() const
{
	return m_health;
}

int CombatUnit::attackPower() const
{
	return 0;
}
