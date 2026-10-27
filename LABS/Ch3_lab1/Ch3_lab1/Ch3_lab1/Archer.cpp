#include <iostream>

#include "Archer.h"




Archer::Archer(int t_health, int t_arrowPower) : CombatUnit{ t_health }
{
	std::cout << "+ Archer\n";
	m_arrowPower = t_arrowPower;
}

Archer::~Archer()
{
	std::cout << "- Archer\n";
}

int Archer::arrowPower() const
{
	return m_arrowPower;
}

int Archer::attackPower() const
{
	return m_arrowPower;
}
