//training bot main.cpp labsheet 2


#include <iostream>
#include "TrainingBot.h"

int main()
{
	std::cout << "Training bot!\n\n\n";

	TrainingBot bot;
	std::cout << "the robots starting health: " << bot.health() << std::endl;

	bot.takeDamage(25);
	std::cout << "Bot took 25 damage!! \n Current bot hp: " << bot.health();

	return 0;
}