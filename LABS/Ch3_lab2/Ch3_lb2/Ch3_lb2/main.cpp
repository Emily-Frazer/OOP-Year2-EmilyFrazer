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

	// Virtual calls: direct shield, base view, direct heal.
	GameAbility const* abilities[]{ &shield, nullptr, &heal };
	int activated{ activateReady(abilities, 3) };
	std::cout << "Activated: " << activated << std::endl;
	std::cout << "Powers: " << shield.power() << "  " << heal.power() << std::endl;

	//Boundary checks
	int empty = activateReady(nullptr, 0);
	std::cout << "Empty: " << empty << std::endl;

	int none = activateReady(nullptr, 1);
	std::cout << "Missing array:" << none << std::endl;

	GameAbility* pOwned{ new HealAbility{ 7 } };
	std::cout << "owned action" << std::endl << std::endl;
	pOwned->activate();
	delete pOwned;
	pOwned = nullptr;


	std::cout << "Leaving scope" << std::endl;




	return 0;
}