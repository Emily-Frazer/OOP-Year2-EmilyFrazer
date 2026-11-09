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
