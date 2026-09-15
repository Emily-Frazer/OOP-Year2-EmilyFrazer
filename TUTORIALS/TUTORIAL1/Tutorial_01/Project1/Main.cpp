#include <iostream>
#include <string>
#include <limits>

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
	int bonus = 0;
	std::cout << "Enter bonus 0-50\n";
	while (true)
	{
		if (std::cin >> bonus && bonus >= 0 && bonus <= 50)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		if (std::cin.eof() || std::cin.bad())
		{
			std::cerr << "Input ended or became unavailable.\n";
			return 1;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Try an interger from 0 to 50.\n";
	}
	return 0;
}
