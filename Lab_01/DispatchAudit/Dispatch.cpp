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
	bool accepted = false; // is the input accepted

	//user input
	
	while (accepted == false)
	{
		std::cout << "Please enter how many units you want to order: ";
		std::cin >> unitAmt;
		if (std::cin.fail())
		{
			std::cout << "error! please make sure you are entering a number between 0 and 60" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (unitAmt >= 0 && unitAmt < 60)
			{
				accepted = true;
			}
			else
			{
				std::cout << "Please enter a number between 0 and 60. " << std::endl;
			}
		}
	}


	return unitAmt;
}