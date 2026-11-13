#pragma once 
#include <typeinfo>

class ArenaObject;

int readGuardHealth(ArenaObject const* t_object);
bool isExactGuard(ArenaObject const* t_object, const type_info& targeType);
int requireGuardHealth(ArenaObject const& t_object);
int countGuardViews(ArenaObject const* const* t_objects,
    int t_count);
int countExactGuards(ArenaObject const* const* t_objects,
    int t_count);