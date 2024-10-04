#include "test.h"

START_TEST(tc_s21_acos_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 6);
}
END_TEST

START_TEST(tc_s21_acos_2) {
  double x = 0.3;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 6);
}
END_TEST

START_TEST(tc_s21_acos_3) {
  double x = -0.1;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 6);
}
END_TEST

START_TEST(tc_s21_acos_4) {
  double x = -1;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 6);
}
END_TEST

START_TEST(tc_s21_acos_5) {
  double x = 1.5;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(tc_s21_acos_6) {
  double x = _NAN;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(tc_s21_acos_7) {
  double x = _INF;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(tc_s21_acos_8) {
  double x = -1.5;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

Suite *test_s21_acos(void) {
  Suite *s = suite_create("s21_acos_bad");
  TCase *tc = tcase_create("s21_acos_test_case");
  tcase_add_test(tc, tc_s21_acos_1);
  tcase_add_test(tc, tc_s21_acos_2);
  tcase_add_test(tc, tc_s21_acos_3);
  tcase_add_test(tc, tc_s21_acos_4);
  tcase_add_test(tc, tc_s21_acos_5);
  tcase_add_test(tc, tc_s21_acos_6);
  tcase_add_test(tc, tc_s21_acos_7);
  tcase_add_test(tc, tc_s21_acos_8);
  suite_add_tcase(s, tc);
  return (s);
}
