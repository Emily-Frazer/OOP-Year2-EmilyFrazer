#ifndef TRAINING_BOT_H 
#define TRAINING_BOT_H 

class TrainingBot
{
public:
    //default constructors
    TrainingBot() = default;
    TrainingBot(int t_health);

    //functions for bot
    int health() const;
    void takeDamage(int t_amount);
    bool isAlive() const;

private:
    //variables
    int m_health{ 100 };

};

#endif 