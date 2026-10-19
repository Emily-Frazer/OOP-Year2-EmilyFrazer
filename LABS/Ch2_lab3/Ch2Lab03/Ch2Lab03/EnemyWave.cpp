#include "EnemyWave.h"
#include "Enemy.h"

EnemyWave::EnemyWave(int t_count)
{
	if (t_count < 0 or t_count > 5)
	{
		t_count = 0;
		m_enemies = nullptr;
	}
	else
	{
		m_count = t_count;
		m_enemies = new Enemy[m_count];

	}

}
EnemyWave::~EnemyWave()
{
	delete &m_enemies[m_count];
}

int EnemyWave::count() const
{
	return m_count;
}

bool EnemyWave::damageEnemy(int t_index, int t_amount)
{
	if (t_index < 0 or t_index > m_count)
	{
		return false;
	}
	else
	{
		m_enemies[t_index].takeDamage(t_amount);
		return true;
	}
	
}

int EnemyWave::healthAt(int t_index) const
{
	if (t_index < 0 or t_index > m_count)
	{
		return m_enemies[t_index].health();
	}
	else
	{
		return -1;
	}
	
}

int EnemyWave::aliveCount() const
{
	int count = 0;
	for (int i = 0; i < m_count; i++)
	{
		if (m_enemies[i].isAlive() == true)
		{
			count++;
		}
	}
	return count;
}

int EnemyWave::totalHealth() const
{
	int total = 0;
	for (int i = 0; i < m_count; i++)
	{
		total = total + m_enemies[i].health();  
	}
	return total;
}
