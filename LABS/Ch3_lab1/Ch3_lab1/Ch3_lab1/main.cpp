//Chapter 3 lab 1

//Emily frazer  OOP Years 2 c00322789
#include  <iostream>

#include "CombatUnit.h"
#include "Archer.h"


int main()
{
	std::cout << "Combat unit inheritence lab \n";

	//Base Unit (COMBAT UNIT ONLY)
	CombatUnit guard{ 60 };
	std::cout <<"Guard health is: " << guard.health() << "\n";
	std::cout << "Guard attack power is: " << guard.attackPower() << "\n";

	//Archer unit (USING ARCHER CLASS)
	Archer archer{ 80,12 };
	std::cout << "Archer health is:" << archer.health() << "\n";
	std::cout << "Archer attack power is: " << archer.attackPower() << "\n";
	

	//COPY AND VIEWS
	std::cout << "\n\nCopied things for task 4\n\n";

	Archer archer2{ 80, 12 };
	CombatUnit baseCopy{ archer2 };
	CombatUnit const& baseView{ archer2 };
	CombatUnit const* pBase{ &archer2 };

	std::cout << "Archer attack power: " << archer2.attackPower() << "\n";
	std::cout << "BaseCopy attack Power: " << baseCopy.attackPower() << "\n";
	std::cout << "BaseView attack power: " << baseView.attackPower() << "\n";
	std::cout << "pBase attack power: " << pBase->attackPower() << "\n";
	std::cout << "Archer attack power: " << archer2.attackPower() << "\n";

	//known object cast (STATIC CAST STUFF)
	std::cout << "Part 5!!!\n\n";
	Archer archer3{ 75, 9 };
	CombatUnit* pUnit{ &archer3 };
	Archer* pRecovered{ static_cast<Archer*>(pUnit) };

	std::cout << "pUnit health: " << pUnit->health() << "\n";
	std::cout << "pRecovered attack: " << pRecovered->attackPower() << "\n";


	return 0;
}