#include "test.h"

START_TEST(tc_s21_ceil_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

START_TEST(tc_s21_ceil_2) {
  double x = 1.3;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

START_TEST(tc_s21_ceil_3) {
  double x = 1;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

START_TEST(tc_s21_ceil_4) {
  double x = -1;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

START_TEST(tc_s21_ceil_5) {
  double x = sqrt(3);
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

START_TEST(tc_s21_ceil_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(tc_s21_ceil_7) {
  double x = _INF;
  ck_assert_ldouble_eq(INFINITY, s21_ceil(x));
}
END_TEST

START_TEST(tc_s21_ceil_8) {
  double x = -sqrt(3);
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), _EPS);
}
END_TEST

Suite *test_s21_ceil(void) {
  Suite *s = suite_create("s21_ceil_bad");
  TCase *tc = tcase_create("s21_ceil_test_case");
  tcase_add_test(tc, tc_s21_ceil_1);
  tcase_add_test(tc, tc_s21_ceil_2);
  tcase_add_test(tc, tc_s21_ceil_3);
  tcase_add_test(tc, tc_s21_ceil_4);
  tcase_add_test(tc, tc_s21_ceil_5);
  tcase_add_test(tc, tc_s21_ceil_6);
  tcase_add_test(tc, tc_s21_ceil_7);
  tcase_add_test(tc, tc_s21_ceil_8);
  suite_add_tcase(s, tc);
  return (s);
}
