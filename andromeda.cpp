#include "andromeda.h"

using namespace std;

Andromeda::Andromeda(int spd, int heal, bool dft):Boss(spd, heal, dft)
{
    setSpeed(spd);
    setHealth(heal);
    setDefeat(dft);
    image.load(":/Images/andromeda.png");
    rect = image.rect();
    BossHit = FALSE;
    xdir = -2;
    ydir = 2;
}

Andromeda::Andromeda():Boss()
{

    speed = 4;
    health = 100;
    setDefeat(FALSE);

    image.load(":/Images/andromeda.png");
    rect = image.rect();
    BossHit = FALSE;
    xdir = 0;
    ydir = 2;
}

Andromeda::~Andromeda()
{}

void Andromeda::resetState()
{
    rect.moveTo(QPoint(500,50));
}

void Andromeda::resetState(int a, int b)
{
    rect.moveTo(a,b);
}

void Andromeda::autoMove()
{
    rect.translate(xdir, ydir);

    if(rect.bottom() >= 600)
        {ydir = -speed;}
    if(rect.top() <= 0)
        {ydir = speed;}
}


void Andromeda::moveRight()
{

}

void Andromeda::moveLeft()
{

}

void Andromeda::moveTop()
{

}

void Andromeda::moveBottom()
{

}

void Andromeda::setDamage()
{
    int heal = getHealth();
    setHealth(heal-50);
    //BossHit = FALSE;
    cout << getHealth() << endl;
}

int Andromeda::getRight()
{
    return (rect.right());
}

int Andromeda::getBottom()
{
    return (rect.bottom());
}

QRect Andromeda::getRect()
{
    return rect;
}

QImage & Andromeda::getImage()
{
    return image;
}
