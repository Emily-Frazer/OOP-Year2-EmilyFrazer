//Chapter 3 lab 1

//Emily frazer  OOP Years 2 c00322789
#include  <iostream>

#include "CombatUnit.h"
#include "Archer.h"


int main()
{
	std::cout << "Combat unit inheritence lab \n";
	CombatUnit guard{ 60 };
	std::cout <<"Guard health is: " << guard.health() << "\n";
	std::cout << "Guard attack power is: " << guard.attackPower() << "\n";

	Archer archer{ 80,12 };
	std::cout << "Archer health is:" << archer.health() << "\n";
	std::cout << "Archer attack power is: " << archer.attackPower() << "\n";
	

	return 0;
}