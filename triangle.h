#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>

struct Point {
    double x, y;
};

double distance(const Point &p1, const Point &p2);

struct Triangle {
    Point A, B, C;

    double area() const;
    bool vyrodzhenyi() const; 
    bool heron(const Point &P) const;
    bool vector(const Point &P) const;
    bool contains(const Point &P, int method) const;
    bool onborder(const Point &P) const;

};

#endif
