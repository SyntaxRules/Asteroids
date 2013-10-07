/********************************************************************
 * Bullet .h file
 * Authors: Justin Ricks and Devyn Stott
 *******************************************************************/

#ifndef ENUM
#define ENUM
enum Type { BULLET, SHIP, ROCK };
#endif // ENUM   

#ifndef BULLET_H
#define BULLET_H

#include "asteroids.h"

class Bullet : public Projectile
{
  public:
   Bullet();
   Bullet(float dx, float dy) : life(30) { };

   virtual void operator ++ (int postfix);
   virtual void draw();
   virtual Type getType() { return BULLET; }
   virtual void event(const Interface * pUI, Asteroids *)  { }; /* Do nothing */
   virtual void hit(Projectile * rhs, Asteroids *) { };
  private:
   int life;
   
};

#endif // BULLET_H
