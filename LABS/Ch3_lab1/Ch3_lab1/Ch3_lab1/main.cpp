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

	//Archer archer{ 80,12 };
	//std::cout << "Archer health is:" << archer.health() << "\n";
	//std::cout << "Archer attack power is: " << archer.attackPower() << "\n";
	

	//copied things for task 4
	std::cout << "\n\nCopied things for task 4\n\n";

	Archer archer{ 80, 12 };
	CombatUnit baseCopy{ archer };
	CombatUnit const& baseView{ archer };
	CombatUnit const* pBase{ &archer };

	std::cout << "Archer attack power: " << archer.attackPower() << "\n";
	std::cout << "BaseCopy attack Power: " << baseCopy.attackPower() << "\n";
	std::cout << "BaseView attack power: " << baseView.attackPower() << "\n";
	std::cout << "pBase attack power: " << pBase->attackPower() << "\n";
	std::cout << "Archer attack power: " << archer.attackPower() << "\n";


	return 0;
}