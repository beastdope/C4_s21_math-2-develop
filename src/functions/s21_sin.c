#include "../s21_math.h"

long double s21_sin(double x) {
  if (x > 0 && x > 2 * S21_PI) {
    double temp = x / (2 * S21_PI);
    x = x - (int)temp * 2 * S21_PI;
  } else if (x < 0 && x < -2 * S21_PI) {
    double temp = x / (2 * S21_PI);
    x = x - (int)temp * 2 * S21_PI;
  }
  long double sum = 0.0;
  long double y = (long double)x;
  long double t = y;
  int p = 0;
  while (s21_fabs(t) > S21_EPS / 10 && p < 10000) {
    sum += t;
    p++;
    t *= -y * y / (2.0 * p + 1.0) / (2.0 * p);
  }
  if (x != x || x == _INF) {
    sum = s21_NaN;
  }
  return sum;
}