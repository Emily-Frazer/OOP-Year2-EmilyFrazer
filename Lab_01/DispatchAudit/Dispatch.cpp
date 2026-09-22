// Write your own implementation for the published practical specification.
#include <iostream>
#include <string>
#include <limits>

#include "Dispatch.h"

std::string depotInput()
{
	//variables
	std::string depotName = "";
	//user input

	std::cout << "Please enter the name of the Depot: ";
	std::getline(std::cin, depotName);

	if (depotName.length() == 0) //error check for blank name
	{
		std::cout << "error";
	}

	std::cout << depotName << std::endl;
	return depotName;
}

int orderInput()
{
	//variables
	int unitAmt; 

	//user input
	std::cout << "Please enter how many units you want to order: ";

	//error checking
	if (!(std::cin >> unitAmt))
	{
		std::cout << "please enter a number";
	}

	while (unitAmt <= 0 || unitAmt > 60) //add the check for letters bestie
	{
		std::cout << "please enter an amount more than 0";
		std::cin >> unitAmt;

	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return unitAmt;
}