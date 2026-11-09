#include "ArenaObjects.h"

#include <iostream>

Guard::Guard(int t_health)
{
	m_health = t_health;

}

void Guard::report() const
{
	std::cout << "Guards Health: " << m_health << std::endl;
}

int Guard::health() const
{
	return m_health;
}

//Elite Guard things
EliteGuard::EliteGuard(int t_health, int t_bonus) : Guard{t_health}
{
	m_bonus = t_bonus;
}

void EliteGuard::report() const
{
	std::cout << "Elite guard health: " << health() << "\nGuard bonus:" << m_bonus << std::endl;
}

int EliteGuard::bonus() const
{
	return m_bonus;
}

//SupplyCrate things
SupplyCrate::SupplyCrate(int t_items)
{
	m_items = t_items;
}

void SupplyCrate::report() const
{
	std::cout << "Supply crate items count:" << m_items << std::endl;
}

int SupplyCrate::items() const
{
	return m_items;
}
