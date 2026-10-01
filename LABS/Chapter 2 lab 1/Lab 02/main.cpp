//training bot main.cpp labsheet 2


#include <iostream>
#include "TrainingBot.h"

int main()
{
	std::cout << "Training bot!\n";

	TrainingBot bot;
	std::cout << "the robots starting heealth: " << bot.health();

	return 0;
}