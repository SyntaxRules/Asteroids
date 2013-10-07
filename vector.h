/***********************************************************************
* Program:
*    Project 4, Asteroids -- vector.h
*    Brother Helfrich, CS165
* Authors:
*    Devyn Stott, Justin Ricks
* Summary: 
*    Please introduce yourself to our best friend, the vector class.
*    The vector class stores our speed and position of different objects.
*    It has overloaded opperators to move the position of a given
*    object forward.
*    We hope you enjoy it as much as we do.
************************************************************************/

#include "point.h"

#ifndef VECTOR_H
#define VECTOR_H

class Vector : public Point
{
  public:
   Vector()                  : Point(),   dx(0 ), dy(0 ) {};
   Vector(const Point & pt)  : Point(pt), dx(0 ), dy(0 ) {};
   Vector(float dx, float dy): Point(),   dx(dx), dy(dy) {};
   
   void operator ++ (int postfix );
   void operator += (Vector & rhs);
   float operator - (Vector rhs  );
   
   float getDx() const { return dx; };
   float getDy() const { return dy; };
   void setDx(float newDx) { dx = newDx; };
   void setDy(float newDy) { dy = newDy; };
   void addDx(float   add) { dx += add;  };
   void addDy(float   add) { dy += add;  };
   friend float minDistance(Vector a, Vector b);
  private:
   float dy;
   float dx;
};

#endif
