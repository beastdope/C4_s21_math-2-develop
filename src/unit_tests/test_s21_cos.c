#include "test.h"

START_TEST(tc_s21_cos_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

START_TEST(tc_s21_cos_2) {
  double x = 1.3;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

START_TEST(tc_s21_cos_3) {
  double x = -4;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

START_TEST(tc_s21_cos_4) {
  double x = S21_PI + 1;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

START_TEST(tc_s21_cos_5) {
  double x = _INF;
  ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(tc_s21_cos_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(tc_s21_cos_7) {
  double x = 100000.321;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

START_TEST(tc_s21_cos_8) {
  double x = -34567.123121;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), _EPS);
}
END_TEST

Suite *test_s21_cos(void) {
  Suite *s = suite_create("s21_cos_bad");
  TCase *tc = tcase_create("s21_cos_test_case");
  tcase_add_test(tc, tc_s21_cos_1);
  tcase_add_test(tc, tc_s21_cos_2);
  tcase_add_test(tc, tc_s21_cos_3);
  tcase_add_test(tc, tc_s21_cos_4);
  tcase_add_test(tc, tc_s21_cos_5);
  tcase_add_test(tc, tc_s21_cos_6);
  tcase_add_test(tc, tc_s21_cos_7);
  tcase_add_test(tc, tc_s21_cos_8);
  suite_add_tcase(s, tc);
  return (s);
}
