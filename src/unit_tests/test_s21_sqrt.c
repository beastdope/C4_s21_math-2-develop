#include "test.h"

START_TEST(tc_s21_sqrt_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sqrt_2) {
  double x = 1.213123;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), _EPS);
}
END_TEST

START_TEST(tc_s21_sqrt_3) {
  double x = -123.123123;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(tc_s21_sqrt_4) {
  double x = _INF;
  ck_assert_ldouble_eq(INFINITY, s21_sqrt(x));
}
END_TEST

START_TEST(tc_s21_sqrt_5) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

Suite *test_s21_sqrt(void) {
  Suite *s = suite_create("s21_sqrt_bad");
  TCase *tc = tcase_create("s21_sqrt_test_case");
  tcase_add_test(tc, tc_s21_sqrt_1);
  tcase_add_test(tc, tc_s21_sqrt_2);
  tcase_add_test(tc, tc_s21_sqrt_3);
  tcase_add_test(tc, tc_s21_sqrt_4);
  tcase_add_test(tc, tc_s21_sqrt_5);
  suite_add_tcase(s, tc);
  return (s);
}
