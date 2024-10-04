#include "test.h"

START_TEST(tc_s21_tan_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_tan_2) {
  double x = 1.3;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_tan_3) {
  double x = -4;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_tan_4) {
  double x = S21_PI + 1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_tan_5) {
  double x = _INF;
  ck_assert_ldouble_nan(s21_tan(x));
}
END_TEST

START_TEST(tc_s21_tan_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_tan(x));
}
END_TEST

START_TEST(tc_s21_tan_7) {
  double x = 1000.321;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), _EPS);
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *s = suite_create("s21_tan_bad");
  TCase *tc = tcase_create("s21_tan_test_case");
  tcase_add_test(tc, tc_s21_tan_1);
  tcase_add_test(tc, tc_s21_tan_2);
  tcase_add_test(tc, tc_s21_tan_3);
  tcase_add_test(tc, tc_s21_tan_4);
  tcase_add_test(tc, tc_s21_tan_5);
  tcase_add_test(tc, tc_s21_tan_6);
  tcase_add_test(tc, tc_s21_tan_7);
  suite_add_tcase(s, tc);
  return (s);
}
