//chapter 3 lab 03
//c00322789
//emily frazer
#include "ArenaObjects.h"

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


	return 0;
}