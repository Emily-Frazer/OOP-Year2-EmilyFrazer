#include "TrainingBot.h"


int TrainingBot::health() const
{
	return m_health; //returns the health of the robot
}

void TrainingBot::takeDamage(int t_amount) //makes health go down when called
{
	if (m_health > 0)
	{
		m_health -= t_amount;
		if (m_health <= 0) //dont let it go under 0
		{
			m_health = 0;
		}
	}
	
}
