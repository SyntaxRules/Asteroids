/***********************************************************************
* Program:
*    Project 2, Skeet -- score.h
*    Brother Helfrich, CS165
* Author:
*    Devyn Stott, Justin Ricks
* Summary: 
*    The Score class is here! Draws, and store the score for a given game.
*    Keeps the computers score and the users score.
************************************************************************/

#ifndef SCORE_H
#define SCORE_H

#include "point.h"
#include "uiDraw.h"

enum {HIT, FAIL};

class Score
{
  public:
   Score();
   void draw();
   
   int getFail() { return score[FAIL]; };
   int getHit() { return score[HIT];  };
   void addScore(int add) { score[HIT] += add;};
   void operator ++ (int postfix);
   void operator -- (int postfix);
   Point & getHitPos()  { return hitPos;  };
   Point & getFailPos() { return failPos; };
  private:
   int score[2];
   Point hitPos;
   Point failPos;
};

#endif // SCORE_H
