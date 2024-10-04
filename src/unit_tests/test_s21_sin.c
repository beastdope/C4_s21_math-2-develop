#include "test.h"

START_TEST(tc_s21_sin_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sin_2) {
  double x = 1.3;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sin_3) {
  double x = -4;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sin_4) {
  double x = S21_PI + 1;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sin_5) {
  double x = _INF;
  ck_assert_ldouble_nan(s21_sin(x));
}
END_TEST

START_TEST(tc_s21_sin_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_sin(x));
}
END_TEST

START_TEST(tc_s21_sin_7) {
  double x = 100000.321;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sin_8) {
  double x = -34567.123121;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), _EPS);
}
END_TEST

Suite *test_s21_sin(void) {
  Suite *s = suite_create("s21_sin_bad");
  TCase *tc = tcase_create("s21_sin_test_case");
  tcase_add_test(tc, tc_s21_sin_1);
  tcase_add_test(tc, tc_s21_sin_2);
  tcase_add_test(tc, tc_s21_sin_3);
  tcase_add_test(tc, tc_s21_sin_4);
  tcase_add_test(tc, tc_s21_sin_5);
  tcase_add_test(tc, tc_s21_sin_6);
  tcase_add_test(tc, tc_s21_sin_7);
  tcase_add_test(tc, tc_s21_sin_8);
  suite_add_tcase(s, tc);
  return (s);
}
