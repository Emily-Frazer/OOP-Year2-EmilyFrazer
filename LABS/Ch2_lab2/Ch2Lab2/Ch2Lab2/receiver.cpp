#include "receiver.h"
#include "beacon.h"

Receiver::Receiver(int t_x)
{
	m_x = t_x;
}

int Receiver::rangeTo(Beacon const&t_beacon) const
{
	int distance;
	if (m_x < t_beacon.x())
	{
		distance = t_beacon.x() - m_x;
	}
	else
	{
		distance = m_x - t_beacon.x(); 
	}

	return distance;
}