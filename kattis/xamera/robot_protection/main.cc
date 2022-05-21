#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

#include "chain_hull.h"

using namespace std;



double polygonArea(Point* points, int num);
void quicksort(Point *A, int len);

istream& operator>>(istream& is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

ostream& operator<<(ostream& os, Point &p) {
    os << p.x << ',' << p.y;
    return os;
}


int main() {
    int beacon_count{};
    static Point beacons[10000];
    static Point hull[10000];


    while (cin >> beacon_count && beacon_count != 0)
    {
        for (int i{}; i < beacon_count; ++i) {
            cin >> beacons[i];
        }

        quicksort(beacons, beacon_count);
        int hull_count = chainHull_2D(beacons, beacon_count, hull);
        double result = polygonArea(hull, hull_count);


        cout << fixed << setprecision(1) << result << endl;
    }

    return 0;
}



// Algorithm for finding the area of a polygon, given
// points in a counter-clockwise order.
// Inspired by: http://www.mathopenref.com/coordpolygonarea2.html
// among others
double polygonArea(Point* points, int num)
{
    double area{};

    for (int i{1}; i < num; ++i) {
        area += (points[i].x + points[i-1].x)
              * (points[i].y - points[i-1].y);
    }
    return area/2;
}

//quicksort, inspired by: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
void quicksort(Point *A, int len)
{
  if (len < 2) return;

  Point pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;
    
    swap(A[i], A[j]);
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}
