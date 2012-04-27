#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

class Ball
{

  public:
    Ball();
    ~Ball();

  public:
    void resetState(int, int);
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();

    void setXDir(int);
    void setYDir(int);
    void setHit(bool);
    void setSpeed(int);

    bool getHit();
    int getXDir();
    int getYDir();
    int getSpeed();
    int getTop();
    QRect getRect();
    QImage & getImage();

  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    bool hit;
    QImage image;
    QRect rect;

};

#endif
