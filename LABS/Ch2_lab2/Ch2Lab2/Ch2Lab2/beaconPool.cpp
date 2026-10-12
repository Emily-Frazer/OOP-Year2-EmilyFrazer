#include "beaconPool.h"
#include <iostream>
int BeaconPool::s_successfulRequests{ 0 };

int BeaconPool::request(int t_strength)
{
	int newBeacon = 0;
	if (t_strength > 100 or t_strength < 0) //sorry i dont have the pipe symbol on my keyboard
	{
		std::cout << "invalid strength, please enter between 0 and 100";
		return -1;
	}
	else
	{
		for (int i = 0; i <= CAPACITY; i++)
		{
			if (m_beacons[i].active() == false)
			{
				s_successfulRequests++;
				m_beacons[i].activate(t_strength);
				newBeacon = i;
				break;
			}
			if (m_beacons[0].active() == true && m_beacons[1].active() == true && m_beacons[2].active() == true)
			{
				newBeacon = -1; //for when all beacons are already active
			}
		}

		return newBeacon;
	}
}

bool BeaconPool::release(int t_index)
{
	if (t_index < 0 or t_index > CAPACITY)
	{
		return false; //break out before YOU break something
	}

	if (m_beacons[t_index].active() == true)
	{
		m_beacons[t_index].reset();
		return true;
	}

	else
	{
		return false;
	}
}

int BeaconPool::activeCount() const
{
	int activeAmt = 0;
	for (int i = 0; i <= CAPACITY; i++)
	{
		if (m_beacons[i].active() == true)
		{
			activeAmt++;
		}
	}
	return activeAmt;
}

int BeaconPool::strengthAt(int t_index) const
{
	if (t_index < 0 or t_index > CAPACITY)
	{
		return -1;
	}
	else
	{
		return m_beacons[t_index].strength();
	}
}

int BeaconPool::successfulRequests()
{
	return s_successfulRequests;
}
