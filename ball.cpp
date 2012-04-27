#include "ball.h"
#include <iostream>

Ball::Ball()
{
  hit = FALSE;

  speed = 1;

  xdir = 2;
  ydir = -2;

  image.load(":/Images/bouncers.png");
  rect = image.rect();



}

Ball::~Ball() {
  std::cout << ("Ball deleted\n");
}


void Ball::autoMove()
{   
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = speed;
  }

  if (rect.right() >=1000) {
    xdir = -(speed);
  }

  if (rect.top() <= 0) {
   ydir = speed;
  }
}

void Ball::resetState(int a, int b)
{
  rect.moveTo(a, b);
}

void Ball::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Ball::moveTop(int top)
{
  rect.moveTop(top);
}

void Ball::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Ball::moveRight(int right)
{
  rect.moveRight(right);
}

void Ball::setXDir(int x)
{
  xdir = x;
}

void Ball::setYDir(int y)
{
  ydir = y;
}

void Ball::setHit(bool Hit)
{
 hit = Hit;
}

void Ball::setSpeed(int Spd)
{
 speed = Spd;
}

bool Ball::getHit()
{
 return hit;
}

int Ball::getXDir()
{
  return xdir;
}

int Ball::getYDir()
{
  return ydir;
}

int Ball::getTop()
{
    return (rect.top());
}

int Ball::getSpeed()
{
 return speed;
}

QRect Ball::getRect()
{
  return rect;
}

QImage & Ball::getImage()
{
  return image;
}
