#include <iostream>
#include "Abilities.h"
#include "Runner.h"


int main()
{
	std::cout << "THEE virtual stuff lab" << std::endl;

	//non virtual stuffs
	ShieldAbility shield{ 20 };
	HealAbility heal{ 15 };
	GameAbility const& view{ shield };

	std::cout << "Direct: ";
	shield.activate();

	std::cout << "Base view: ";
	view.activate();

	std::cout << "Second Type:";
	heal.activate();




	return 0;
}