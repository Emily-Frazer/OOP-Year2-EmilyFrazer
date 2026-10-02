#ifndef TANK_H
#define TANK_H
class TankAI;

class Tank 
{
public:
	int rangeTo(TankAI const t_ai) const;
	int x() const { return m_x; }

private:
	int m_x{10};


};





#endif
