#include "enemylaser.h"

EnemyLaser::EnemyLaser()
{
 xdir = 0;
 ydir = 6;
 contact = FALSE;

 image.load(":/Images/enemyfire.png");
 rect = image.rect();
 rect.moveTo(0,0);
}

EnemyLaser::~EnemyLaser()
{}

void EnemyLaser::Reset(int X, int Y)
{
  rect.moveTo(X,Y);

}

void EnemyLaser::autoMove()
{
  rect.translate(xdir, ydir);
}

void EnemyLaser::setContact(bool Hit)
{
 contact = Hit;
}

bool EnemyLaser::getContact()
{
 return contact;
}

QRect EnemyLaser::getRect()
{
 return rect;
}

QImage & EnemyLaser::getImage()
{
 return image;
}

