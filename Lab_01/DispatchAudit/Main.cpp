// Write your own implementation for the published practical specification.

#include <iostream>
#include <string>

//main function, everything go in here
int main()
{
	//declaringvariables for use
	std::string depotName = "";
	int unitAmt = 0;

	//user input
	
	std::cout << "Please enter the name of the Depot: ";
	std::getline(std::cin, depotName);
	
	std::cout << depotName << std::endl;

	std::cout << "Please enter how many units you want to order: ";
	std::cin >> unitAmt;



	return 0;
}


