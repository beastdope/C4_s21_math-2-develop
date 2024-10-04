#include "../s21_math.h"

long double s21_pow(double constant, double x) {  // const^x
  long double result = 0;  // переменная результата
  long double buff_result = _NAN;  // переменна которая фиксирует
                                   // предыдущий резльтат для выхода из цикла
  long double count = 0;  // счетчик кол-вы итераций цикла (n)
  long double x_stepen = 1;   // x^n
  long double ln_stepen = 1;  // (ln a)^n
  long double factorial = 1;  // n!
  if (constant != constant || x != x ||
      (constant < 0 && s21_fabs(s21_fmod(x, 1)) > 0)) {  // где-то поймали нан
    result = _NAN;
  } else if (constant != 0 && constant != _INF && x != _INF &&
             constant != _NAN && x != _NAN && x != 0) {  // обычный повчик
    int flag = 0;
    if (constant < 0) {
      constant = -constant;
      if (s21_fmod(x, 2) != 0.0) {
        flag = 2;
      }
    }
    while (result != buff_result) {
      buff_result = result;
      count++;
      result += x_stepen * ln_stepen / factorial;
      x_stepen *= x;  // x^n
      ln_stepen *= s21_log(constant);
      factorial *= count;
    }
    if (flag == 2) {
      result = -result;
    }
  } else if (constant == _INF || x == _INF) {  // словили бесконечность где-то
    if ((constant == _INF && x != 0) || (s21_fabs(constant) > 1 && x == _INF)) {
      result = _INF;
    } else if (s21_fabs(constant) == 1 || x == 0) {
      result = 1;
    } else {
      result = 0;
    }
  } else {  // result == 0 при const == 0
    if (x == 0) {
      result = 1;  // cлучай когда 0 в степени 0 (0^0 == 1)
    }
  }
  return (result);
}
