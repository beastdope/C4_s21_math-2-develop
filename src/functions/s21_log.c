#include "../s21_math.h"

long double s21_log(double x) {  // написал Леня. Я вообще без понятия, как оно
                                 // воркает, но Леня легенда
  long double result = 0;  // переменная результата
  int flag = 0;
  if (x != x) {
    result = _NAN;
  } else if (x == _INF) {
    result = _INF;
  } else if (x == 0) {
    result = -_INF;
  } else if (x < 0) {
    result = _NAN;
  } else {
    long double buff_result = _NAN;  // переменна которая фиксирует предыдущий
                                     // резльтат для выхода из цикла
    long count = 1;  // счетчик кол-вы итераций цикла
    int minus = 1;
    if (x >= 2) {
      flag = 1;
      x = 1.0 / x;  // гениальное решение проблемы окрестности (Лёне респект)
    }
    long double constant = x - 1;  // подсчёт константы в степени
    long double temp = 0;
    while (result != buff_result) {
      buff_result = result;
      temp = constant / count;
      result += minus * temp;  // ряд тейлора
      minus *= -1;
      constant *= (x - 1);
      count++;
    }
    if (flag == 1) {
      result = -result;
    }
  }
  return (result);
}
