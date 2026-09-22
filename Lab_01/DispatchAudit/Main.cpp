// Write your own implementation for the published practical specification.

#include <iostream>
#include <string>
#include <limits>

#include "Dispatch.h"

//main function, everything go in here
int main()
{
	//declaringvariables for use
	std::string depotName = "";
	int unitAmt = 0;

	//function calls and stuff

	depotName = depotInput();
	unitAmt = orderInput();

	std::cout << depotName << std::endl;
	std::cout << orderInput << std::endl;

	if (unitAmt == -1)
	{
		std::cout << "Error! please enter an actual number";
	}
	




	return 0;
}


