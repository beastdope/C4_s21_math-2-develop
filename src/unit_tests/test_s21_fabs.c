#include "test.h"

START_TEST(tc_s21_fabs_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(fabs(x), s21_fabs(x), _EPS);
}
END_TEST

START_TEST(tc_s21_fabs_2) {
  double x = 1.213123;
  ck_assert_ldouble_eq_tol(fabs(x), s21_fabs(x), _EPS);
}
END_TEST

START_TEST(tc_s21_fabs_3) {
  double x = -123.123123;
  ck_assert_ldouble_eq_tol(fabs(x), s21_fabs(x), _EPS);
}
END_TEST

START_TEST(tc_s21_fabs_4) {
  double x = _INF;
  ck_assert_ldouble_eq(INFINITY, s21_fabs(x));
}
END_TEST

START_TEST(tc_s21_fabs_5) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_fabs(x));
}
END_TEST

Suite *test_s21_fabs(void) {
  Suite *s = suite_create("s21_fabs_bad");
  TCase *tc = tcase_create("s21_fabs_test_case");
  tcase_add_test(tc, tc_s21_fabs_1);
  tcase_add_test(tc, tc_s21_fabs_2);
  tcase_add_test(tc, tc_s21_fabs_3);
  tcase_add_test(tc, tc_s21_fabs_4);
  tcase_add_test(tc, tc_s21_fabs_5);
  suite_add_tcase(s, tc);
  return (s);
}
