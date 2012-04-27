#ifndef GAME2_H
#define GAME2_H


#include "ball.h"
#include "brick.h"
#include "player.h"
#include "laser.h"
#include "altair.h"
#include <QWidget>
#include <QKeyEvent>

using namespace std;

class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = 0);
    ~Game();

  public:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void PDeath();
    void CDeath();
    void victory();
    void checkCollision();

  private:
    int x;
    int MC;
    int timerId;
    int deathID;
    int clearEnemy;
    Ball * ball[30];
    Player * player;
    Altair * altair;
    Brick * bricks1[5];
    Brick * bricks2[5];
    Brick * bricks3[5];
    Laser * laser;
    bool Death;
    bool E1C;
    bool E2C;
    bool HitBoss;
    bool Invade1;
    bool Invade2;
    bool Respawn;
    bool CityLost;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool laserShot;

};

#endif
