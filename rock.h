/**************************************************************
 * Rock.h
 * This is the parent class to LargeRock, MedRock and SmallRock
 * and contains the functions that are simalar betweent the three
 * Authors: Justin Ricks and Devyn Stott
 *************************************************************/

#ifndef ENUM
#define ENUM
enum Type { BULLET, SHIP, ROCK };
#endif // ENUM     


#ifndef ROCK_H
#define ROCK_H
#define SMALL_ROTATION 7
#define MED_ROTATION   5
#define LARGE_ROTATION 3

#include "asteroids.h"
#include "shootable.h"
#include "uiDraw.h"

class Projectile;

#include <iostream>
using namespace std;

/*****************************************************
 * Parent class
 ****************************************************/
class Rock : public Shootable
{
  public:
   Rock() : Shootable() {};

   float getSize()  { return size;}
   virtual void operator ++ (int postfix) = 0;
   
   void draw();
   virtual void hit  (Projectile * rhs, Asteroids *) = 0;
   virtual void event(const Interface * pUI, Asteroids *) { }; // ignore the event
   virtual Type getType() { return ROCK; };
  protected:
   float size;
   int numSides;
};

/*************************************************
 * Medium Rock
 ************************************************/
class MedRock : public Rock
{
  public:
   MedRock();
   virtual void operator ++ (int postfix) { v++; rotation += MED_ROTATION; };
   virtual void hit(Projectile * rhs, Asteroids *);
};

/**************************************************
 * Small Rock
 *************************************************/
class SmallRock : public Rock
{
  public:
   SmallRock();
   virtual void operator ++ (int postfix) { v++; rotation += SMALL_ROTATION; };
   virtual void hit(Projectile * rhs, Asteroids *);
  private:

};

/**************************************************
 * Large Rock
 *************************************************/
class LargeRock : public Rock
{
  public:
   LargeRock();
   virtual void operator ++ (int postfix) { v++; rotation += LARGE_ROTATION; };
   virtual void hit(Projectile * rhs, Asteroids *);
};


#endif //ROCK_H
