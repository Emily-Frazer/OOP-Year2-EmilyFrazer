//chapter 2 lab 03
//Emily Frazer - c00322789
#include <iostream>

#include "Enemy.h"



int main()
{
	std::cout << "enemy wave memory lab \n";
	

	//dingle dynamic enemy
	Enemy *pEnemy;
	pEnemy = new Enemy;
	pEnemy->health();
	std::cout << "The enemy health is:" << pEnemy->health() << "\n";
	pEnemy->takeDamage(30);
	std::cout << "The new enemy health: " << pEnemy->health() << "\n";

	delete pEnemy;
	pEnemy = nullptr;

	//array of enemies
	const int enemyCount{ 3 };
	int aliveNum = 0;
	int totalHp = 0;

	Enemy *pEnemies[enemyCount];
	pEnemies[enemyCount] = new Enemy;
	pEnemies[0]->takeDamage(25);
	pEnemies[1]->takeDamage(100);
	pEnemies[2]->takeDamage(60);

	for (int i = 0; i < enemyCount; i++)
	{
		if (pEnemies[i]->isAlive() == true)
		{
			aliveNum++;
		}
		totalHp = totalHp + pEnemies[i]->health();
	}
	std::cout << "Enemy in slot 0 Remaining health: " << pEnemies[0]->health() <<
		"\nEnemy in slot 1 Remaining health" << pEnemies[1]->health() <<
		"\n Enemy in slot 2 Remaining Health" << pEnemies[2]->health() <<
		"\n\nAlive enemies" << aliveNum << "\nTotal hp left = " << totalHp;


	//delete pEnemies[enemyCount];
	//pEnemies[enemyCount] = nullptr;

	return 0;
}