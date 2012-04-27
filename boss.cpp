#include "boss.h"

Boss::Boss()
{
    speed = 2;
    defeated = false;
    xdir = speed;
}

Boss::Boss(int spd, int heal, bool dft)
{
    speed = spd;
    health = heal;
    defeated = dft;
}

Boss::~Boss()
{};

void Boss::setXDir(int x)
{
    xdir = x;
}

void Boss::setYDir(int y)
{
    ydir = y;
}

void Boss::setSpeed(int spd)
{
    speed = spd;
}

void Boss::setHealth(int heal)
{
    health = heal;
}

void Boss::setDefeat(bool dft)
{
    defeated = dft;
}

int Boss::getSpeed()
{
    return speed;
}

int Boss::getHealth()
{
    return health;
}

int Boss::getXDir()
{
    return xdir;
}

int Boss::getYDir()
{
    return ydir;
}

bool Boss::getDefeat()
{
    return defeated;
}

