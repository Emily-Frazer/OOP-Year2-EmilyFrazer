#include "Player.h"

void Player::takeDamage()
{
	if (m_health > 0)
	{
		m_health--;
	}
}

int Player::health() const
{
	return m_health;
}

Player::PlayerType Player::playerType() const
{
	return m_class;
}

bool Player::isAlive()
{
	return m_health > 0;
}