#include "test.h"

START_TEST(tc_s21_exp_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), _EPS);
}
END_TEST

START_TEST(tc_s21_exp_2) {
  double x = 1.3;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), _EPS);
}
END_TEST

START_TEST(tc_s21_exp_3) {
  double x = -4;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), _EPS);
}
END_TEST

START_TEST(tc_s21_exp_4) {
  double x = S21_PI + 1;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), _EPS);
}
END_TEST

START_TEST(tc_s21_exp_5) {
  double x = _INF;
  ck_assert_ldouble_eq(INFINITY, s21_exp(x));
}
END_TEST

START_TEST(tc_s21_exp_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_exp(x));
}
END_TEST

START_TEST(tc_s21_exp_7) {
  double x = 100000.321;
  ck_assert_ldouble_eq(INFINITY, s21_exp(x));
}
END_TEST

Suite *test_s21_exp(void) {
  Suite *s = suite_create("s21_exp_bad");
  TCase *tc = tcase_create("s21_exp_test_case");
  tcase_add_test(tc, tc_s21_exp_1);
  tcase_add_test(tc, tc_s21_exp_2);
  tcase_add_test(tc, tc_s21_exp_3);
  tcase_add_test(tc, tc_s21_exp_4);
  tcase_add_test(tc, tc_s21_exp_5);
  tcase_add_test(tc, tc_s21_exp_6);
  tcase_add_test(tc, tc_s21_exp_7);
  suite_add_tcase(s, tc);
  return (s);
}
