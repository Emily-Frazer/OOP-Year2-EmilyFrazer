#include "Runner.h"
#include "Abilities.h"
#include <iostream>

int activateReady(GameAbility const* const* t_abilities, int t_count)
{
    int step = 0;
    if (t_count < 0 or t_count > 4)
    {
        return -1; //error! do not access the other stuff justt leave immediately
    }
    else if (t_count == 0)
    {
        return 0;
    }
    else if (t_abilities == nullptr)
    {
        return -1;
    }

    for (int i = 0; i< t_count; i++)
    {

        if(t_abilities[i] != nullptr)
        {
            t_abilities[i]->activate();
            step++;   
        }
      

    }
    return step; //return amount of activations!
}
