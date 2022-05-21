#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double p, q, r, s, t, u;
double best_value;

double formula(double x) {
  return 
    p * exp(-x) +
    q * sin(x) +
    r * cos(x) +
    s * tan(x) +
    t * x * x +
    u;
}

double find_best(double low, double high) {
  double best_x = low;
  double step = (high-low)/10;
  double res, x;
  best_value = formula(best_x);

  for (x = low+step; x <= high; x += step) {
    res = formula(x);
    /*cout << "x: " <<  best_x << " value: " << formula(best_x) << endl;*/
    /*printf("%f, %f, %f, %f\n", x, res, abs(res), abs(best_value));*/
    if ((res > 0 ? res : -res) < (best_value> 0 ? best_value : -best_value)) {
      best_x = x;
      best_value = res;
    }
  }
  return best_x;
}


int main() {
  double best_x;

  while (scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) == 6) {


    best_x = find_best(0, 1);
    /*printf("%f, %f\n", best_x, formula(best_x));*/
    best_x = find_best(best_x - 0.1, best_x + 0.1);
    best_x = find_best(best_x - 0.01, best_x + 0.01);
    best_x = find_best(best_x - 0.001, best_x + 0.001);
    best_x = find_best(best_x - 0.0001, best_x + 0.0001);

    if ((best_value > 0 ? best_value : -best_value) > 0.0001 ) {
      /*printf("%f\n", best_value);*/
      printf("No solution\n");
    }
    else {
      /*cout << "x: " <<  setprecision(4) << best_x << " value: " << setprecision(5) << formula(best_x) << endl;*/
      printf("%f\n", best_x);
    }
  }

  return 0;
}


