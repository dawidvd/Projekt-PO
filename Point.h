//
//  Point.h
//  SDL DOMO
//
//

#ifndef SDL_DOMO_Point_h
#define SDL_DOMO_Point_h
struct Point
{
    int x, y;
    
    bool operator < (Point& punkt) const
    {
        return x < punkt.x && y < punkt.y;
    }
    
    bool operator > (Point& punkt) const
    {
        return !(*this < punkt);
    }
    
    Point& operator -= (Point& point)
    {
        x -= point.x;
        y -= point.y;
        return *this;
    }
    
    Point& operator += (Point& point)
    {
        x += point.x;
        y += point.y;
        return *this;
    }
};

#endif
