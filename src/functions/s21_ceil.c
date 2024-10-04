#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if (x != x)
    res = x;
  else if (x == s21_INF || x == s21_N_INF)
    res = x;
  else {
    long double b = (long long int)x;
    long double comp_x = x;
    comp_x *= 10e18;
    long double comp_b = b;
    comp_b *= 10e18;
    if (comp_x - comp_b > 0) {
      res = b;
      res += 1.;
    } else {
      res = b;
    }
  }
  return res;
}