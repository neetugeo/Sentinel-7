#include "game2.h"
#include <iostream>
#include <QPainter>
#include <QApplication>

Game::Game(QWidget *parent)
    : QWidget(parent)
{
  x = 0;
  MC = 0;
  Invade1 = FALSE;
  Invade2 = FALSE;
  Death = FALSE;
  CityLost = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  Respawn = FALSE;
  gameStarted = FALSE;
  E1C = FALSE;
  E2C = FALSE;
  for (int i = 0; i < 30; i++)
      ball[i] = new Ball();
  ball[MC]->resetState(700,50);
  ball[MC+1]->resetState(200,50);
  ball[MC+1]->setSpeed(3);
  player = new Player();
  altair = new Altair();
  altair->resetState();


  //Break the bricks into groups!! Too much iteration for the compiler to handle!

  for (int i = 0; i < 5; i++)
  {bricks1[i] = new Brick(i*50 + 50, 400);}

  for (int i = 0; i < 5; i++)
  {bricks2[i] = new Brick(i*50 + 500, 400);}

  for (int i = 0; i < 5; i++)
  {bricks3[i] = new Brick(i*50 + 750, 400);}
}

Game::~Game() {
 for (int k=0; k<30; k++)
   delete ball[k];

 delete player;

 for (int i=0; i<5; i++) {
   delete bricks1[i];
 }

 for (int i=0; i<5; i++) {
   delete bricks2[i];
 }

 for (int i=0; i<5; i++) {
   delete bricks3[i];
 }
}

void Game::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setPen(QPen(QColor(255,255,255)));
  painter.setBrush(QBrush(QColor(0,0,255)));

  if (Death) {
    QFont font("Courier", 15, QFont::Normal);
    QFontMetrics fm(font);
    int textWidth = fm.width("And his battered ship");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, -30, "And the battered ship");

    textWidth = fm.width("would forever drift");
    painter.drawText(-textWidth/2,-15,"would forever drift");

    textWidth = fm.width("the expanses of space");
    painter.drawText(-textWidth/2,0,"the expanses of space");

    textWidth = fm.width("taking with it");
    painter.drawText(-textWidth/2,15,"taking with it");

    textWidth = fm.width("a wandering soul.");
    painter.drawText(-textWidth/2,30,"a wandering soul.");
  }

  else if(CityLost)
  {
   QFont font("Courier", 15, QFont::Normal);
   QFontMetrics fm(font);

   int textWidth = fm.width("But the Machina were too strong;");
   painter.setFont(font);
   int w = width();
   int h = height();

   painter.translate(QPoint(w/2 ,h/2));
   painter.drawText(-textWidth/2,-15,"But the Machina were too strong;");

   textWidth = fm.width("the two pilots were overcome");
   painter.drawText(-textWidth/2,0,"the two pilots were overcome");

   textWidth = fm.width("before reinforcements ever arrived.");
   painter.drawText(-textWidth/2,15,"before reinforcements ever arrived.");
  }

  else if(gameWon) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory");
  }

  else {
    if(!ball[MC]->getHit())
      {painter.drawImage(ball[MC]->getRect(),ball[MC]->getImage());}

    if(!ball[MC+1]->getHit())
      {painter.drawImage(ball[MC+1]->getRect(),ball[MC+1]->getImage());}

    painter.drawImage(player->getRect(),player->getImage());

    if(!altair->getDefeat())
    {painter.drawImage(altair->getRect(),altair->getImage());}


    if (!laser->getContact())
      painter.drawImage(laser->getRect(),laser->getImage());

    for (int i=0; i<5; i++) {
        if (!bricks1[i]->isDestroyed())
          painter.drawImage(bricks1[i]->getRect(), bricks1[i]->getImage());
    }

    for (int i=0; i<5; i++) {
        if (!bricks2[i]->isDestroyed())
          painter.drawImage(bricks2[i]->getRect(), bricks2[i]->getImage());
    }

    for (int i=0; i<5; i++) {
        if (!bricks3[i]->isDestroyed())
          painter.drawImage(bricks3[i]->getRect(), bricks3[i]->getImage());
    }

  }

}

void Game::timerEvent(QTimerEvent *event)
{
 if (!ball[MC]->getHit())
     ball[MC]->autoMove();

 if (laserShot == TRUE && !laser->getContact())
   {
    laser->autoMove();
   }


 if (!ball[MC+1]->getHit())
  ball[MC+1]->autoMove();

 if (laserShot == TRUE && !laser->getContact())
   {
    laser->autoMove();
   }

  checkCollision();

  if (Respawn == TRUE)
  {if (MC < 30)
    {MC = MC + 2;}
   ball[MC]->resetState(200, 50);
   ball[MC+1]->resetState(800, 50);
   ball[MC+1]->setSpeed(3);
   E1C = FALSE;
   E2C = FALSE;
   Respawn = FALSE;}

  repaint();
}



void Game::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Left:
       {
         int x = player->getRect().x();
        for (int i=1; i<=5; i++)
          player->moveLeft(x--);
        break;
       }
    case Qt::Key_Right:
        {
          int x = player->getRect().x();
          for (int i=1; i<=5; i++)
            player->moveRight(x++);
        }
        break;
    case Qt::Key_Up:
        {
        int y = player->getRect().y();
        for (int i = 1; i<-5; i++)
            player->moveUp(x++);
        }
        break;
    case Qt::Key_P:
        {
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    case Qt::Key_A:
        {
         laser = new Laser();
         laser->Reset(player->getRect().left()+25, player->getRect().top());
         laserShot = TRUE;
        }
    default:
        QWidget::keyPressEvent(event);
    }
}

void Game::startGame()
{
  if (!gameStarted) {
    ball[MC]->resetState(700,50);
    ball[MC+1]->resetState(200,50);
    player->resetState();
    altair->resetState();

    for (int i=0; i<5; i++) {
      bricks1[i]->setDestroyed(FALSE);
    }


    for (int i=0; i<5; i++) {
      bricks2[i]->setDestroyed(FALSE);
    }


    for (int i=0; i<5; i++) {
      bricks3[i]->setDestroyed(FALSE);
    }

    Death = FALSE;
    gameWon = FALSE;
    gameStarted = TRUE;
    timerId = startTimer(10);
  }
}

void Game::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId);
   }
}

void Game::PDeath()
{
  killTimer(timerId);
  Death = TRUE;
  gameStarted = FALSE;
}

void Game::CDeath()
{
 killTimer(timerId);
 CityLost = TRUE;
 gameStarted = FALSE;
}

void Game::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  gameStarted = FALSE;
}

void Game::checkCollision()
{

  if (ball[MC]->getRect().bottom() > 600)
    {
      if (Invade1 != TRUE)
          Invade1 = TRUE;
      else if (Invade1 == TRUE)
          Invade2 = TRUE;

     E1C = TRUE;
     ball[MC]->~Ball();}


  if (ball[MC+1]->getRect().bottom() > 600)
    {
      if (Invade1 != TRUE)
          Invade1 == TRUE;
      else if (Invade1 == TRUE)
          Invade2 = TRUE;

     E2C = TRUE;
     ball[MC+1]->~Ball();}


  if (Invade1 == TRUE && Invade2 == TRUE)
    {CDeath();}


  if (E1C == TRUE && E2C == TRUE)
  {Respawn = TRUE;}

  if (altair->getRect().intersects(laser->getRect()) && laser != NULL)
  {   altair->BossHit = TRUE;
      laser->setContact(TRUE);
      cout << "Altair Hit!" << endl;
      altair->setDamage();
      laser->Reset(0,0);
      laser->~Laser();}


  if (altair->getHealth() <= 0)
   {altair->setDefeat(TRUE);
      victory();}

  if (ball[MC]->getRect().intersects(laser->getRect()))
  {ball[MC]->setHit(TRUE);
      ball[MC]->resetState(0,0);
   ball[MC]->~Ball();
   E1C = TRUE;
   laser->Reset(0,0);
   laser->~Laser();
   cout << "Collision" << endl;}

  if (ball[MC+1]->getRect().intersects(laser->getRect()))
  {ball[MC+1]->setHit(TRUE);
      ball[MC+1]->resetState(0,0);
   ball[MC+1]->~Ball();
   E2C = TRUE;
   laser->~Laser();
   cout << "Collision!" << endl;}

  /*for (int i=0, j=0; i<5; i++) {
    if (bricks1[i]->isDestroyed()) {
      j++;
    }
  }*/

  if ((ball[MC]->getRect()).intersects(player->getRect()))
  {
      PDeath();
  }


  if ((ball[MC+1]->getRect()).intersects(player->getRect()))
  {
      PDeath();
  }


  for (int i=0; i<5; i++) {
    if ((laser->getRect()).intersects(bricks1[i]->getRect()))
    {
     bricks1[i]->setDestroyed(TRUE);
     delete bricks1[i];
     laser->setContact(TRUE);
     laser->Reset(0,0);
     laser->~Laser();

    }
  }

  for (int i=0; i<5; i++) {
    if ((laser->getRect()).intersects(bricks2[i]->getRect()))
    {
     bricks2[i]->setDestroyed(TRUE);
     delete bricks2[i];
     laser->setContact(TRUE);
     laser->Reset(0,0);
     laser->~Laser();
    }
  }


  for (int i=0; i<5; i++) {
    if ((laser->getRect()).intersects(bricks3[i]->getRect()))
    {
     bricks3[i]->setDestroyed(TRUE);
     delete bricks3[i];
     laser->setContact(TRUE);
     laser->Reset(0,0);
     laser->~Laser();
    }
  }

  for (int i=0; i<5; i++) {
      if ((ball[MC]->getRect()).intersects(bricks1[i]->getRect()))
    {
     bricks1[i]->setDestroyed(TRUE);
     delete bricks1[i];

     if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
         ball[MC]->setYDir((ball[MC]->getSpeed()));
     if (ball[MC]->getYDir() == (ball[MC]->getSpeed()))
         ball[MC]->setYDir(-(ball[MC]->getSpeed()));
    }
  }


  for (int i=0; i<5; i++) {
      if ((ball[MC]->getRect()).intersects(bricks2[i]->getRect()))
    {
     bricks2[i]->setDestroyed(TRUE);
     delete bricks2[i];

     if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
         ball[MC]->setYDir(ball[MC]->getSpeed());
     if (ball[MC]->getYDir() == ball[MC]->getSpeed())
         ball[MC]->setYDir(-(ball[MC]->getSpeed()));
    }
  }

  for (int i=0; i<5; i++) {
      if ((ball[MC]->getRect()).intersects(bricks3[i]->getRect()))
    {
     bricks3[i]->setDestroyed(TRUE);
     delete bricks3[i];

     if (ball[MC]->getYDir() == -(ball[MC]->getSpeed()))
         ball[MC]->setYDir((ball[MC]->getSpeed()));
     if (ball[MC]->getYDir() == (ball[MC]->getSpeed()))
         ball[MC]->setYDir(-(ball[MC]->getSpeed()));
    }
  }


  for (int i=0; i<5; i++) {
      if ((ball[MC+1]->getRect()).intersects(bricks1[i]->getRect()))
    {
     bricks1[i]->setDestroyed(TRUE);
     delete bricks1[i];

     if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
     if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
    }
  }


  for (int i=0; i<5; i++) {
      if ((ball[MC+1]->getRect()).intersects(bricks2[i]->getRect()))
    {
     bricks2[i]->setDestroyed(TRUE);
     delete bricks2[i];

     if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
     if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
    }
  }



  for (int i=0; i<5; i++) {
      if ((ball[MC+1]->getRect()).intersects(bricks3[i]->getRect()))
    {
     bricks3[i]->setDestroyed(TRUE);
     delete bricks3[i];

     if (ball[MC+1]->getYDir() == -(ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir((ball[MC+1]->getSpeed()));
     if (ball[MC+1]->getYDir() == (ball[MC+1]->getSpeed()))
         ball[MC+1]->setYDir(-(ball[MC+1]->getSpeed()));
    }
  }


}
