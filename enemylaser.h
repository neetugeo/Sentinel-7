#ifndef ENEMYLASER_H
#define ENEMYLASER_H

#include <QRect>
#include <QImage>


class EnemyLaser
{
public:
    EnemyLaser();
    ~EnemyLaser();

public:
    void autoMove();
    void Reset(int, int);
    void setXDir(int);
    void setYDir(int);
    void setContact(bool);

    bool getContact();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

private:
    int xdir;
    int ydir;
    bool contact;
    QRect rect;
    QImage image;
};

#endif // ENEMYLASER_H
