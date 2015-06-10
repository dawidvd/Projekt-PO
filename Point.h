#ifndef SDL_DOMO_Point_h
#define SDL_DOMO_Point_h
struct Point
{
    int x, y;
    
    bool operator < (Point& point) const
    {
        return x < point.x && y < point.y;
    }
    
    bool operator > (Point& point) const
    {
        return !(*this < point);
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
