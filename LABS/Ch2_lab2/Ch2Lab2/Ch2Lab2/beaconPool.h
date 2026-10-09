#ifndef BEACON_POOL_H
#define BEACON_POOL_H

#include "beacon.h"

class Beaconpool
{
public:
	static constexpr int CAPACITY{ 3 };
	
	Beaconpool() = default;
	int request(int t_strength);
	bool release(int t_index);
	int activeCount() const;
	int strengthAt(int t_index) const;
	static int s_successfulRequests();

private:
	Beacon m_beacons[CAPACITY];
	static int s_successfulRequests;
};


#endif

