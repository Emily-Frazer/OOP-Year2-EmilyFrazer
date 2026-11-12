#include "Inspector.h"
#include "ArenaObjects.h"
#include <typeinfo>

int readGuardHealth(ArenaObject const* t_object)
{
	Guard const* pGuard{dynamic_cast<Guard const*>(t_object)};

	if (pGuard == nullptr)
	{
		return -1;
	}
	else
	{
		return pGuard->health();
	}
}

bool isExactGuard(ArenaObject const* t_object)
{
	//if (t_object == nullptr)
	//{
	//	return false;
	//}
	//else if (typeid(*t_object) == typeid(Guard) || typeid(t_object) == typeid(Guard))
	//{
	//	return true;
	//}
	//else if (typeid(*t_object) != typeid(Guard))
	//{
	//	if (typeid(*t_object) == typeid(EliteGuard))
	//	{
	//		return true;
	//	}
	//}
	//else
	//{
	//	return false;
	//}
	bool sameType = false;

	if (t_object == nullptr) //error checking, do not continue if null
	{
		return false;
	}
	//to check if guard
	if (typeid(*t_object) == typeid(Guard))
	{
		sameType = true;
	}
	else //when not a guard, what is it?
	{
		if (typeid(*t_object) == typeid(EliteGuard)) //check if theyre an elite guard
		{
			sameType = true;
		}
		if (typeid(*t_object) == typeid(ArenaObject))
		{
			sameType = true;
		}
	}


	return sameType;
}
