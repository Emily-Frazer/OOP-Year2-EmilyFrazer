//chapter 2 lab 03
//Emily Frazer - c00322789
#include <iostream>

#include "Enemy.h"
#include "EnemyWave.h"

int main()
{
	std::cout << "enemy wave memory lab \n\n\n SINGLE ENEMY \n";

	// 1. One dynamic Enemy: allocate, damage, print, delete, nullptr.
	Enemy* pEnemy{ new Enemy{} };
	pEnemy->takeDamage(30);
	std::cout << "The enemy health is:" << pEnemy->health() << "\n";
	pEnemy->takeDamage(30);
	std::cout << "The new enemy health: " << pEnemy->health() << "\n\n";
	delete pEnemy;
	pEnemy = nullptr;


	// 2. Raw Enemy array: allocate 3, apply 25/100/60 damage,
	//array of enemies;
	int aliveNum = 0;
	int totalHp = 0;
	const int enemyCount{ 3 };
	//Enemy* pEnemies[enemyCount];
	Enemy* pEnemies{ new Enemy[enemyCount] };

	pEnemies[0].takeDamage(25);
	pEnemies[1].takeDamage(100);
	pEnemies[2].takeDamage(60);

	for (int i = 0; i < enemyCount; i++)
	{
		if (pEnemies[i].isAlive() == true)
		{
			aliveNum++;
		}
		totalHp = totalHp + pEnemies[i].health();
	}
	std::cout << "ENEMY IN MAIN ARRAY\nEnemy in slot 0 Remaining health: " << pEnemies[0].health() <<
		"\nEnemy in slot 1 Remaining health: " << pEnemies[1].health() <<
		"\nEnemy in slot 2 Remaining Health: " << pEnemies[2].health() <<
		"\n\nAlive enemies " << aliveNum << "\nTotal hp left = " << totalHp << "\n\n";
	delete[] pEnemies;
	pEnemies = nullptr;


	// 3. EnemyWave owner: repeat the same damage through its interface.
	EnemyWave wave{ 3 };
	wave.damageEnemy(0, 25);
	wave.damageEnemy(1, 100);
	wave.damageEnemy(2, 60);

	std::cout << "ENEMY FROM WAVE.H\n Enemy in slot 0 Remaining health: " << wave.healthAt(0) <<
		"\nEnemy in slot 1 Remaining health: " << wave.healthAt(1) <<
		"\n nemy in slot 2 Remaining Health: " << wave.healthAt(2) <<
		"\n\nAlive enemies " << wave.aliveCount() << "\nTotal hp left = " << wave.totalHealth();


	// 4. Invalid wave: no allocation, count 0, total 0.
	EnemyWave invalid{ 8 };
	std::cout << "\nINVALID ENEMY FROM WAVE.H\n\nAlive enemies " << invalid.aliveCount() << "\nTotal hp left = " << invalid.totalHealth();
	return 0;
}