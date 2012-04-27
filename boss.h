#ifndef BOSS_H
#define BOSS_H

class Boss
{
protected:
int xdir;
int ydir;
int speed;
int health;
bool defeated;

public:
    Boss();
    Boss(int, int, bool);
    ~Boss();

    void setSpeed(int);
    void setHealth(int);
    void setDefeat(bool);
    void setXDir(int);
    void setYDir(int);

    int getSpeed();
    int getHealth();
    int getXDir();
    int getYDir();
    bool getDefeat();

    virtual void resetState() = 0;
    virtual void autoMove() = 0;
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    virtual void moveTop() = 0;
    virtual void moveBottom() = 0;
};

#endif // BOSS_H
