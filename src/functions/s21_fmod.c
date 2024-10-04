#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (y == 0.0 || x == 0 || x == _INF) {  // на нуль делить низя
    result = _NAN;
  } else {
    int n = 0;
    n = (int)(x / y);  // сколько игреков в иксе???
    result = x - n * y;
  }
  return result;
}
