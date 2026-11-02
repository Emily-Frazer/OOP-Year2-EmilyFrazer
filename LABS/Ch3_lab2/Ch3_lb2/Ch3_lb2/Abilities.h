#ifndef ABILITIES_H
#define ABILITIES_H
class GameAbility
{
public:
	explicit GameAbility(int t_power);
	virtual ~GameAbility() = default;
	void activate() const; // Not virtual yet.
	int power() const;
private:
	int m_power;
};
class ShieldAbility : public GameAbility
{
public:
	explicit ShieldAbility(int t_power);
	void activate() const;
private:
	int m_shieldPower;
};
class HealAbility : public GameAbility
{
public:
	explicit HealAbility(int t_power);
	void activate() const;
private:
	int m_healPower;
};
#endif
