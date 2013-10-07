#include "vector.h"
#include <cmath>
#include <iostream> //for cerr and endl
using namespace std;

#ifndef MINMAX
#define MINMAX

//max Functions
inline int max(int a, int b)
{
   return (a > b) ? a:b;
}

inline int max(int a, int b, int c, int d)
{
   return max(max(a, b), max(c, d));
}

inline float max(float a, float b)
{
   return (a > b) ? a:b;
}

inline float max(float a, float b, float c, float d)
{
   return max(max(a, b), max(c, d));
}

//MIN function
inline int min(int a, int b)
{
   return (a < b) ? a:b;
}

#endif //MINMAX


void Vector :: operator ++ (int postfix)
{
   // Wrapping
   if (y < getYMin())
      y = getYMax();
   if (y > getYMax())
      y = getYMin();
   if (x < getXMin())
      x = getXMax();
   if (x > getXMax())
      x = getXMin();

   x += dx;
   y += dy;
   
   return;
}

void Vector :: operator += (Vector & rhs)
{
   dx += rhs.dx;
   dy += rhs.dy;
}

float minDistance(Vector a, Vector b)
{
   float distance = 0;
   float maxD = max(abs(a.dx), abs(a.dy), abs(b.dx), abs(b.dy));
   cerr << " maxD : " << maxD << endl;
   float minD = ( ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y)) ); //for the first pixel
   for (int i = 1; i < maxD; i++) //for every pixel after that
   {
      cerr << "minD for pixel " << i << ": " << minD << endl;
      distance = ( (( (a.x+a.dx*i/maxD) - (b.x+b.dx*i/maxD) ) * ( (a.x+a.dx*i/maxD) - (b.x+b.dx*i/maxD) ))
                   + (( (a.y+a.dy*i/maxD) - (b.y+b.dy*i/maxD) ) * ( (a.y+a.dy*i/maxD) - (b.y+b.dy*i/maxD) )) );
      minD = min(minD, distance);
   }
   return sqrt(minD);
}
