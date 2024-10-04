#ifndef MATH
#define MATH

#include <stdio.h>
#define s21_INF 1.0 / 0.0
#define s21_N_INF -1.0 / 0.0
#define s21_NaN 0.0 / 0.0
#define S21_EPS 1e-06
#define S21_PI 3.14159265359

#include <stdlib.h>
#define _NAN 0.0 / 0.0
#define _INF 1.0 / 0.0
#define PI 3.14159265358979323846264338327950288419716939937510582
#define ASIN_1 1.5707963267948966
#define _EPS 1e-6
#define _PI 3.14159265358979323846264338327950288419716939937510582

long double s21_factorial_all(int x);
int s21_abs(int x);
long double s21_exp(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_acos(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_floor(double a);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_atan(double n);
long double s21_fabs(double jija);
long double s21_pow(double constant, double x);

#endif
