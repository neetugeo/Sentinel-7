#ifndef BREAKOUT_H
#define BREAKOUT_H


#include "ball.h"
#include "brick.h"
#include "player.h"
#include "laser.h"
#include "tracker.h"
#include "altair.h"
#include "andromeda.h"
#include "runner.h"
#include "life.h"
#include "enemylaser.h"
#include <QWidget>
#include <QKeyEvent>



using namespace std;

class Sentinel : public QWidget
{
  Q_OBJECT

  public:
    Sentinel(QWidget *parent = 0);
    ~Sentinel();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void PDeath();
    void CDeath();
    void victory();
    void field2();
    void checkCollision();
    void startLevel2();
    void startLevel3();
    void secondSetUp();
    void thirdSetUp();


  private:
    int x;
    int lives;
    int lives2;
    int lives3;
    int holdx;
    int MC;
    int M2C;
    int timerId;
    int deathID;
    int clearEnemy;
    int Score;
    Ball * ball[30];
    Tracker * tracker[30];
    Runner * runner[10];
    Player * player;
    Altair * altair;
    Andromeda * andromeda;
    Brick * bricks1[5];
    Brick * bricks2[5];
    Brick * bricks3[5];
    Laser * laser;
    Life * life[5];
    EnemyLaser * enemylaser;
    bool Death;
    bool E1C;
    bool E2C;
    bool Level1;
    bool Level2;
    bool Level3;
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
