#include <math.h>

#include "../s21_math.h"

long double s21_cos(double x) {
  long double result = 0.0;
  if (x == 0) {
    result = 1;
  } else if (x == _INF ||
             x != x) {  // бред собачий от бесконечности косинус находить
    result = _NAN;
  } else {
    x = s21_fmod(x, 2 * _PI);  // берем остаток от пи / 2, тоже самое типо, но
                               // тейлору так приятнее считать
    long double buf =
        1.0;  // переменная для запоминания предыдущего результата в ряде
    int n = 0;  // колво шагов, по совместительству степень для тейлора
    while (result !=
           buf) {  // сравниваем этот и предыдущий шаг для выхода из цикла
      buf = result;
      long double temp =
          s21_pow(-1, n) * (s21_pow(x, 2 * n)) / s21_factorial_all(2 * n);
      result += temp;
      n++;
    }
  }
  return result;
}
