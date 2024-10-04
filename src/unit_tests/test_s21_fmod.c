#include "test.h"

START_TEST(tc_s21_fmod_1) {
  double x = 0.0;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(tc_s21_fmod_2) {
  double x = 3.0;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(tc_s21_fmod_3) {
  double x = -4;
  double y = 0.85;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), _EPS);
}
END_TEST

START_TEST(tc_s21_fmod_4) {
  double x = S21_PI + 1;
  double y = S21_PI;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), _EPS);
}
END_TEST

START_TEST(tc_s21_fmod_5) {
  double x = _INF;
  double y = S21_PI;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(tc_s21_fmod_6) {
  double x = _NAN;
  double y = S21_PI;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

Suite *test_s21_fmod(void) {
  Suite *s = suite_create("s21_fmod_bad");
  TCase *tc = tcase_create("s21_fmod_test_case");
  tcase_add_test(tc, tc_s21_fmod_1);
  tcase_add_test(tc, tc_s21_fmod_2);
  tcase_add_test(tc, tc_s21_fmod_3);
  tcase_add_test(tc, tc_s21_fmod_4);
  tcase_add_test(tc, tc_s21_fmod_5);
  tcase_add_test(tc, tc_s21_fmod_6);
  suite_add_tcase(s, tc);
  return (s);
}
