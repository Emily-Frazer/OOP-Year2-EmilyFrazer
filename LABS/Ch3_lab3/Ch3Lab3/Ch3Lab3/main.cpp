//chapter 3 lab 03
//c00322789
//emily frazer
#include "ArenaObjects.h"
#include "Inspector.h"

#include <iostream>
#include <typeinfo>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "lab 03! arena object inspector\n";

	Guard guard{ 60 };
	EliteGuard elite{ 90,15 };
	SupplyCrate crate{ 4 };

	//changing const pointer.
	ArenaObject const* selected{ &guard };

	selected->report();
	selected = &elite;
	selected->report();
	selected = &crate;
	selected->report();

	//check guard views
	std::cout << readGuardHealth(&guard) <<std::endl;
	std::cout << readGuardHealth(&elite) <<std::endl;
	std::cout << readGuardHealth(&crate) <<std::endl;
	std::cout << readGuardHealth(nullptr)<<std::endl;

	//Exact type checks
	std::cout <<"Guard is exact guard: " << isExactGuard(dynamic_cast<Guard const*>(&guard), typeid(Guard)) << std::endl;
	std::cout <<"Elite is exact guard: " << isExactGuard(dynamic_cast<Guard const*>(&elite), typeid(Guard)) << std::endl;
	std::cout <<"Crate is exact guard: " << isExactGuard(dynamic_cast<Guard const*>(&crate), typeid(Guard)) << std::endl;
	std::cout <<"Elite is exact elite: " << isExactGuard(dynamic_cast<EliteGuard const*>(&elite), typeid(EliteGuard)) << std::endl;
	std::cout << "Pointer is ArenaObject const*: " << isExactGuard(dynamic_cast<ArenaObject const*>(selected), typeid(ArenaObject)) << std::endl;
	
	return 0;
}