#include <math.h>

#include "test.h"
START_TEST(tc_s21_abs_1) {
  int x = 0.0;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(tc_s21_abs_2) {
  int x = -1;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(tc_s21_abs_3) {
  int x = -2;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(tc_s21_abs_4) {
  int x = 3;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(tc_s21_abs_5) {
  int x = _INF;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(tc_s21_abs_6) {
  int x = _NAN;
  ck_assert_ldouble_eq(abs(x), s21_abs(x));
}
END_TEST

Suite *test_s21_abs(void) {
  Suite *s = suite_create("s21_abs_bad");
  TCase *tc = tcase_create("s21_abs_test_case");
  tcase_add_test(tc, tc_s21_abs_1);
  tcase_add_test(tc, tc_s21_abs_2);
  tcase_add_test(tc, tc_s21_abs_3);
  tcase_add_test(tc, tc_s21_abs_4);
  tcase_add_test(tc, tc_s21_abs_5);
  tcase_add_test(tc, tc_s21_abs_6);
  suite_add_tcase(s, tc);
  return (s);
}
