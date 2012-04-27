#include "life.h"

Life::Life(int a, int b)
{
    lost = FALSE;
    image.load(":/Images/heart.png");
    rect = image.rect();
    rect.moveTo(a,b);
}

Life::Life()
{
    lost = FALSE;
    image.load(":/Images/heart.png");
    rect = image.rect();
}

Life::~Life()
{}

void Life::Reset(int a, int b)
{
    rect.moveTo(a,b);
}

void Life::setLost(bool loss)
{
    lost = loss;
}

bool Life::lifeLost()
{
    return lost;
}

QRect Life::getRect()
{
    return rect;
}

QImage & Life::getImage()
{
    return image;
}
