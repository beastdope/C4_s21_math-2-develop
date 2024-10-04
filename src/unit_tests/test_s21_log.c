#include "test.h"

START_TEST(tc_s21_log_1) {
  double x = 0.0;
  ck_assert_ldouble_eq(-INFINITY, s21_log(x));
}
END_TEST

START_TEST(tc_s21_log_2) {
  double x = 1;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), _EPS);
}
END_TEST

START_TEST(tc_s21_log_3) {
  double x = -123.123123;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(tc_s21_log_4) {
  double x = _INF;
  ck_assert_ldouble_eq(INFINITY, s21_log(x));
}
END_TEST

START_TEST(tc_s21_log_5) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

Suite *test_s21_log(void) {
  Suite *s = suite_create("s21_log_bad");
  TCase *tc = tcase_create("s21_log_test_case");
  tcase_add_test(tc, tc_s21_log_1);
  tcase_add_test(tc, tc_s21_log_2);
  tcase_add_test(tc, tc_s21_log_3);
  tcase_add_test(tc, tc_s21_log_4);
  tcase_add_test(tc, tc_s21_log_5);
  suite_add_tcase(s, tc);
  return (s);
}
