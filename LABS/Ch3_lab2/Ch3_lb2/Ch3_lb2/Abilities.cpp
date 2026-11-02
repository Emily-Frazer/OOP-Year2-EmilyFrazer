#include "Abilities.h"
#include <iostream>

//constructor
GameAbility::GameAbility(int t_power)
{
	m_power = t_power;
}

//prints generic ability
void GameAbility::activate() const
{
	std::cout << "Generic ability" << std::endl;
}

//returns m_power
int GameAbility::power() const
{
	return m_power;
}

ShieldAbility::ShieldAbility(int t_power) : GameAbility{ t_power }
{
	m_shieldPower = t_power;
}

void ShieldAbility::activate() const
{
	std::cout << "Shield Power: " << m_shieldPower << std::endl;
}

HealAbility::HealAbility(int t_power) : GameAbility{ t_power }
{
	m_healPower = t_power;
}

void HealAbility::activate() const
{
	std::cout << "Heal power: " << m_healPower <<std::endl;
}
