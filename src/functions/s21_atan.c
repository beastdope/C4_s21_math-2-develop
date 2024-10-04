#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = 0;  // переменная результата
  long double buff_result = 1;  // переменная которая фиксирует предыдущий
                                // резльтат для выхода из цикла
  int count = 0;   // счетчик кол-вы итераций цикла
  int qwerty = 0;  // 2*count +1
  int flag = 0;
  int flag_negative = 0;
  long double buff = 0;
  if (x == _INF) {
    result = 1.570796;
  } else if (x != x) {
    result = _NAN;
  } else {
    if (s21_fabs(x) > 1) {
      x = 1 / x;
      flag = 1;  // Решение проблемы с областью схождения [-1;1] ряда Тейлора
    }
    if (x < 0) {
      x *= -1;
      flag_negative = 1;
    }
    while (s21_fabs(result - buff_result) > _EPS) {
      buff_result = result;
      qwerty = 2 * (count) + 1;
      buff = s21_pow(x, qwerty);
      result += s21_pow(-1, count) * buff / qwerty;
      // printf("orig == %lf fake == %LF x == %f qwerty == %d\n", pow(x,
      // qwerty),s21_pow(x, qwerty), x, qwerty);
      count++;
    }
    if (flag == 1) {
      result = PI / 2 -
               result;  // atan(x) + atan(1/x) == pi / 2
                        // proof --> https://www.youtube.com/watch?v=JuWVWZ_R53g
    }
    if (flag_negative == 1) {
      result *= -1;
    }
  }
  return (result);
}