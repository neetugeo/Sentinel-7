#include "runner.h"

Runner::Runner()
{
    hit = FALSE;

    speed = 3;

    xdir = 0;
    ydir = -3;

    image.load(":/Images/bouncers.png");
    rect = image.rect();
}
Runner::~Runner()
{
}
void Runner::resetState(int a, int b)
{
    rect.moveTo(a,b);
}
void Runner::moveBottom(int bottom)
{
    rect.moveBottom(bottom);
}
void Runner::moveTop(int top)
{
    rect.moveTop(top);
}
void Runner::moveLeft(int left)
{
    rect.moveLeft(left);
}

void Runner::moveRight(int right)
{
    rect.moveRight(right);
}

void Runner::autoMove()
{
    rect.translate(xdir, ydir);
    if (rect.bottom() >=600)
      ydir = -speed;
    if (rect.top() <= 0)
        ydir = speed;
}

void Runner::setXDir(int x)
{
    xdir = x;
}

void Runner::setYDir(int y)
{
    ydir = y;
}

void Runner::setHit(bool Hit)
{
    hit = Hit;
}

void Runner::setSpeed(int spd)
{
    speed = spd;
}

bool Runner::getHit()
{
    return hit;
}

int Runner::getXDir()
{
    return xdir;
}

int Runner::getYDir()
{
    return ydir;
}

int Runner::getSpeed()
{
    return speed;
}

int Runner::getTop()
{
    return rect.top();
}

QRect Runner::getRect()
{
    return rect;
}

QImage & Runner::getImage()
{
    return image;
}
