//tutorial for chapter 2

#include <iostream>
#include <string>
#include <cassert>
#include "Player.h"


int main()
{
	std::cout << std::boolalpha; //prints bools in english rather than numbers
	Player player{};
	player.takeDamage();
	std::cout << player.health() << " " << player.isAlive() << "\n";
	assert(player.health() == 99); // checking to make sure theyre at 99hp
	assert(player.playerType() == Player::PlayerType::WARRIOR); //checking to make sure theyre a warrior


	return 0;
}
