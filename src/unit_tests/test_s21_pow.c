#include "test.h"
START_TEST(tc_s21_pow_1) {
  double x = 1;
  double y = 2;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), _EPS);
}
END_TEST
START_TEST(tc_s21_pow_2) {
  double x = 3;
  double y = -1;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), _EPS);
}
END_TEST
START_TEST(tc_s21_pow_3) {
  double x = -4;
  double y = 0.85;
  ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST
START_TEST(tc_s21_pow_4) {
  double x = S21_PI + 1;
  double y = S21_PI;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), _EPS);
}
END_TEST
START_TEST(tc_s21_pow_5) {
  double x = _INF;
  double y = S21_PI;
  ck_assert_ldouble_eq(INFINITY, s21_pow(x, y));
}
END_TEST
START_TEST(tc_s21_pow_6) {
  double x = S21_PI;
  double y = _NAN;
  ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST
START_TEST(tc_s21_pow_7) {
  double y = _NAN;
  double x = S21_PI;
  ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST
START_TEST(tc_s21_pow_8) {
  double y = _INF;
  double x = S21_PI;
  ck_assert_ldouble_eq(INFINITY, s21_pow(x, y));
}
END_TEST
Suite *test_s21_pow(void) {
  Suite *s = suite_create("s21_pow_bad");
  TCase *tc = tcase_create("s21_pow_test_case");
  tcase_add_test(tc, tc_s21_pow_1);
  tcase_add_test(tc, tc_s21_pow_2);
  tcase_add_test(tc, tc_s21_pow_3);
  tcase_add_test(tc, tc_s21_pow_4);
  tcase_add_test(tc, tc_s21_pow_5);
  tcase_add_test(tc, tc_s21_pow_6);
  tcase_add_test(tc, tc_s21_pow_7);
  tcase_add_test(tc, tc_s21_pow_8);
  suite_add_tcase(s, tc);
  return (s);
}