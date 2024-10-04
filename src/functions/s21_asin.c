#include "../s21_math.h"

long double s21_2n_1(int x) {  // написаная Егором штука для асин
  long double solve = 1;
  for (int i = 1; i <= x; i++) {
    solve *= (2 * i - 1);
  }
  return solve;
}

long double s21_factorial_all(int x) {  // факториальчик, тоже Егора
  long double solve = 1;
  for (int i = 1; i <= x; i++) {
    solve *= i;
  }
  return solve;
}

long double s21_asin(double x) {  // Егоров арксинус
  long double buf = 1.0;
  long double solve = x;
  int i = 1;
  if (x == 1) {
    solve = 1.5707963267948966;
  } else if (x == -1) {
    solve = -1.5707963267948966;
  }
  if (x > 1 || x < -1) {
    solve = _NAN;
  } else {
    while (s21_fabs(solve - buf) > _EPS) {
      buf = solve;
      long double temp = (s21_2n_1(i) * s21_pow(x, 2 * i + 1)) /
                         (s21_pow(2, i) * s21_factorial_all(i) * (2 * i + 1));
      solve += temp;
      i++;
    }
  }
  return solve;
}
