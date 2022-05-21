#include <iostream>

struct Point {
    int x;
    int y;

    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator >(const Point &p) const {
        return p < *this;
    }
};

int chainHull_2D( Point* P, int n, Point* H );
