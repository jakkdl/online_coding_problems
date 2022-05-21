#include <stdio.h>



struct point {
    int x;
    int y;
    double angle;
}

static point points[10000];


bool operator<(point const& lhs, point const& rhs) {
    if (lhs.y < rhs.y) {
        return true;
    }
    return lhs.x < rhs.x;
}


int main() {
    int beacons;


    while (scanf("%d%*1c", &len) && len != 0) {
        int min = 0; //index of "smallest" point
        for (int i=0; i < len; ++i) {
            scanf("%d %d", points[i].x, points[i].y);
            if (points[i] < points[min]) {
                min = i;
            }
        }

    }









    return 0;
}
