#include "test.h"

START_TEST(tc_s21_asin_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 6);
}
END_TEST

START_TEST(tc_s21_asin_2) {
  double x = 1.3;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(tc_s21_asin_3) {
  double x = 1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 6);
}
END_TEST

START_TEST(tc_s21_asin_4) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 6);
}
END_TEST

START_TEST(tc_s21_asin_5) {
  double x = sqrt(3) / 2;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 6);
}
END_TEST

START_TEST(tc_s21_asin_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(tc_s21_asin_7) {
  double x = _INF;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(tc_s21_asin_8) {
  double x = -sqrt(3) / 2;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 6);
}
END_TEST

Suite *test_s21_asin(void) {
  Suite *s = suite_create("s21_asin_bad");
  TCase *tc = tcase_create("s21_asin_test_case");
  tcase_add_test(tc, tc_s21_asin_1);
  tcase_add_test(tc, tc_s21_asin_2);
  tcase_add_test(tc, tc_s21_asin_3);
  tcase_add_test(tc, tc_s21_asin_4);
  tcase_add_test(tc, tc_s21_asin_5);
  tcase_add_test(tc, tc_s21_asin_6);
  tcase_add_test(tc, tc_s21_asin_7);
  tcase_add_test(tc, tc_s21_asin_8);
  suite_add_tcase(s, tc);
  return (s);
}
