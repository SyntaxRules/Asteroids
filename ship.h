#include "asteroids.h"
#include "shootable.h"
#include "uiInteract.h"

#define SHIP_SIZE 10.0

#ifndef SHIP_H
#define SHIP_H

class Ship : public Shootable
{
  private:

  public:
   Ship();
   float getSize() { return SHIP_SIZE; };
   void operator ++ (int postfix) { v++; };
   virtual void hit(Projectile * rhs, Asteroids *) { };
   virtual void draw();
   virtual void event(const Interface * pUI, Asteroids *);
   virtual Type getType() { return SHIP; };
};

#endif // SHIP_H
