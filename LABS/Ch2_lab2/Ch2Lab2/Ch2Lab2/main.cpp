//chapter 2 lab 2 for oop
//
#include <iostream>

#include "Beacon.h"
#include "Receiver.h"

int main()
{
	std::cout << "\nConnection Check\n";
	Beacon demoBeacon{ 10 };
	Receiver receiver{ 35 };

	std::cout << "Range to beacon: " << receiver.rangeTo(demoBeacon) << "\n";

	return 0;
}