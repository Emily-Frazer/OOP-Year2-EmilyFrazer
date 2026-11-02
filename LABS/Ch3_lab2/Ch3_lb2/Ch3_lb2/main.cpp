#include <iostream>
#include "Abilities.h"
#include "Runner.h"


int main()
{
	std::cout << "THEE virtual stuff lab" << std::endl;

	//virtual stuffs
	ShieldAbility shield{ 20 };
	HealAbility heal{ 15 };
	GameAbility const& view{ shield };

	std::cout << "Direct: ";
	shield.activate();

	std::cout << "Base view: ";
	view.activate();

	std::cout << "Second Type:";
	heal.activate();


	//start of the owned stuff
	GameAbility* pOwned{ new HealAbility{ 7 } };
	std::cout << "owned action" << std::endl;
	pOwned->activate();




	return 0;
}