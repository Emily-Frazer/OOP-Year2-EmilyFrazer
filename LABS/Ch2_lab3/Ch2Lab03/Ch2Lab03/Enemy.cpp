#include "Enemy.h"

void Enemy::takeDamage(int t_amount)
{
	if (m_health > 0) //when over 0 health
	{
		m_health = m_health - t_amount;
		if (m_health <= 0)
		{
			m_health = 0; //making sure no go below 0
		}
	}
}

int Enemy::health() const
{
	return m_health;
}

bool Enemy::isAlive() const
{
	return m_health > 0;
}
