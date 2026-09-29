#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	enum class PlayerType {WARRIOR,WIZARD,ARCHER};
	static constexpr int MAX_HEALTH{ 100 };

	Player() = default; //default constructor

	void takeDamage(); //player taking damage
	int health() const;
	PlayerType playerType() const;
	bool isAlive();

private:
	int m_health{ MAX_HEALTH };
	PlayerType m_class{ PlayerType::WARRIOR };



};










#endif