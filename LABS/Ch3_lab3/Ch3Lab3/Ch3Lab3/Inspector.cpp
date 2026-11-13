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

bool isExactGuard(ArenaObject const* t_object, const std::type_info& targeType)
{
	if (t_object == nullptr)
	{
		return false;
	}
	
	return typeid(*t_object) == targeType;
}
