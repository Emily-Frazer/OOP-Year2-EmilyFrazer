#ifndef TRAINING_BOT_H 
#define TRAINING_BOT_H 

class TrainingBot
{
public:
    int health() const;
    void takeDamage(int t_amount);

private:
    int m_health{ 100 };
};

#endif 