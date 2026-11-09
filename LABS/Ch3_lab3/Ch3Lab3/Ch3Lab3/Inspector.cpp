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
	if (t_object == nullptr)
	{
		return false;
	}
	else if (typeid(*t_object) == typeid(Guard))
	{
		return true;
	}
	else if (typeid(*t_object) != typeid(Guard))
	{
		if (typeid(*t_object) == typeid(EliteGuard))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
