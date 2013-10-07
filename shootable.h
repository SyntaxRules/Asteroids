#include "asteroids.h"

#ifndef SHOOTABLE_H
#define SHOOTABLE_H

/*******************************************
 * The shootable class is a specialized version
 *   of projectile that can be shot by bullets
 *******************************************/
class Shootable : public Projectile
{
  public:
   Shootable() : rotation(0) {};
   
   // The hit detection is the only variant from a projectile
   virtual void hit(Projectile * rhs, Asteroids *) = 0;

  protected:
   int rotation;
};

#endif // SHOOTABLE_H
