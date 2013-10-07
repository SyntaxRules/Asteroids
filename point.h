/*****************************************
 * POINT Class
 * A very simple point class.  
 ****************************************/
#define POINT_MAX 256

#ifndef _POINT_H
#define _POINT_H

/*******************
 * POINT
 *******************/
class Point
{
public:
   // constructors
   Point()                : x(0.0 ),  y(0.0 ) {};
   Point(bool noError)    : x(0.0 ),  y(0.0 ) {};
   Point(const Point & pt): x(pt.x),  y(pt.y) {};
   Point(float x, float y): x(x   ),  y(y   ) {};
      
   // getters
   float getX()    const { return  x;         };
   float getY()    const { return  y;         };
   float getXMax() const { return  POINT_MAX; };
   float getYMax() const { return  POINT_MAX; };
   float getXMin() const { return -POINT_MAX; };
   float getYMin() const { return -POINT_MAX; };

   // setters
   void setX(float x)    { this->x = x;   };
   void setY(float y)    { this->y = y;   };
   void addX(float dx)   { this->x += dx; };
   void addY(float dy)   { this->y += dy; };

   void operator = (const Point & pt) { this->x = pt.x; this->y = pt.y; };

protected:
   float x;
   float y;
};

#endif 
