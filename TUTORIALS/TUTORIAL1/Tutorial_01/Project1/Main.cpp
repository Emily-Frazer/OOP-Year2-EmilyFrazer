#include <iostream>
#include <string>

#include "Report.h"

int main()
{
	Report::printHeading();
	std::string playerName;
	std::cout << "Player Name:  ";
	if (!std::getline(std::cin, playerName))
	{
		std::cout << "No player name was read.\n";
		return 1;

	}
	std::cout << "Preparing  report for " << playerName << "\n";
	return 0;
}
