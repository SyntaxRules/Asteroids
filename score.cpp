/***********************************************************************
* Program:
*    Project 2, Skeet -- score.cpp
*    Brother Helfrich, CS165
* Author:
*    Devyn Stott, Justin Ricks
* Summary: 
*    Has functions and calls function from uiDraw.h to draw the score on
*    the screen to be used by a number of different games. This code
*    is very reusable ina  number of different situations.
************************************************************************/

#include "uiDraw.h"
#include "score.h"

/*************************************************************************
 * Score::Score()
 * Default Constructor!
 * Sets intial position to top left and right of the screen!
 ***********************************************************************/
Score::Score()
{
   score[HIT]  = 0;
   score[FAIL] = 0;

   failPos.setX(failPos.getXMin() + 5);
   failPos.setY(failPos.getYMax() - 5);

   hitPos.setX(hitPos.getXMax() - (5 + 40));
   hitPos.setY(hitPos.getYMax() - 5);
}

/**********************************************************************
 * Score::operator ++ (postfix)
 * Increments the users score after winning a point, gets all ready to be
 * drawn
 ********************************************************************/
void Score::operator ++ (int postfix)
{
   score[HIT]++;
   return;
}

/**********************************************************************
 * Score::operator -- (postfix)
 * Increments the computers score after the user loses, gets all ready to be
 * drawn.
 ********************************************************************/
void Score::operator -- (int postfix)
{
   score[FAIL]++;
   return;
}

/******************************************************************
 * Score::draw()
 * Draws the user and computers scores on the screen! Excellent!
 * Calls a function in uiDraw.h to do this for us.
 *****************************************************************/
void Score::draw()
{
   drawNumber(hitPos, score[HIT]);
   //drawNumber(failPos, score[FAIL]); No fail in this program.
   return;
}
