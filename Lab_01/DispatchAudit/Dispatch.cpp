// Write your own implementation for the published practical specification.
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#include "Dispatch.h"

std::string depotInput()
{
	//variables
	std::string depotName = "";
	//user input

	std::cout << "Please enter the name of the Depot: ";
	std::getline(std::cin, depotName);

	if (depotName.length() == 0) //error check for blank name
	{
		std::cout << "error";
	}

	std::cout << depotName << std::endl;
	return depotName;
}

int orderInput()
{
	//variables
	int unitAmt;
	bool accepted = false; // is the input accepted

	//user input
	
	while (accepted == false)
	{
		std::cout << "Please enter how many units you want to order: ";
		std::cin >> unitAmt;
		if (std::cin.fail())
		{
			std::cout << "error! please make sure you are entering a number between 0 and 60" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (unitAmt >= 0 && unitAmt < 60)
			{
				accepted = true;
			}
			else
			{
				std::cout << "Please enter a number between 0 and 60. " << std::endl;
			}
		}
	}


	return unitAmt;
}

/// <summary>
/// reads batches.txt for the stock counts
/// </summary>
void readFile()
{
	int batch; //the number read from file
	int batchAmt = 0; //total batches for the stock
	int lowBatchAmt = 0; //amt of batches with a number less than 10
	const int MAX_ENTRIES = 12; //maximum amt of antries in the file
	int total = 0; //total amount of stock

	std::ifstream input("batches.txt"); //checking if the file is being read
	if (!input)
	{
		std::cout << "Error! cannot read the file :( \n";
	}
	else 
	{
		std::cout << "reading file . . . \n";
	}

	while (input >> std::ws && !input.eof()) //while reading file
	{
		if (!(input >> batch) || batch > 40 || batch < 0) //if insdide the given amount
		{

		}
		else
		{
			if (batch < 10) //checking for ower batches
			{
				lowBatchAmt++;
			}
			batchAmt++;
			total += batch;
			if (batchAmt == MAX_ENTRIES) //if entries hit 12
			{
				break;
			}
		}
		
		

	}
	//displaying everything
	std::cout << "Low batch amount (batches under 10): " << lowBatchAmt << std::endl;
	std::cout << "Total batch amount: " << batchAmt << std::endl;
	std::cout << "Total stock amount: " << total << std::endl;


}
