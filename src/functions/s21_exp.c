#include "../s21_math.h"

long double s21_exp(double x) {  // написал Леня. Я вообще без понятия, как оно
                                 // воркает, но Леня легенда
  long double result = 0;  // переменная результата
  if (x != x) {
    result = _NAN;
  } else if (x == _INF) {
    result = _INF;
  } else {
    long double buff_result = 1;  // переменна которая фиксирует предыдущий
                                  // резльтат для выхода из цикла
    long double factorial = 1;  // подсчёт факториала в знаменателе
    double count = 0;  // счетчик кол-вы итераций цикла
    long double constant = 1;  // подсчёт константы в степени
    while (result != buff_result) {
      count++;
      buff_result = result;
      result += (constant / factorial);
      constant *= x;
      factorial *= count;
    }
  }
  return (result);
}
