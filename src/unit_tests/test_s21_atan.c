#include "test.h"
START_TEST(tc_s21_atan_1) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_atan_2) {
  double x = 1.1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_atan_3) {
  double x = 1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST
START_TEST(tc_s21_atan_4) {
  double x = -1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_atan_5) {
  double x = 1.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

// START_TEST(tc_s21_atan_6) {
//   double x = _NAN;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
// }
// END_TEST

START_TEST(tc_s21_atan_7) {
  double x = _INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

START_TEST(tc_s21_atan_8) {
  double x = -1.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), _EPS);
}
END_TEST

Suite *test_s21_atan(void) {
  Suite *s = suite_create("s21_atan_bad");
  TCase *tc = tcase_create("s21_atan_test_case");
  tcase_add_test(tc, tc_s21_atan_1);
  tcase_add_test(tc, tc_s21_atan_2);
  tcase_add_test(tc, tc_s21_atan_3);
  tcase_add_test(tc, tc_s21_atan_4);
  tcase_add_test(tc, tc_s21_atan_5);
  // tcase_add_test(tc, tc_s21_atan_6);
  tcase_add_test(tc, tc_s21_atan_7);
  tcase_add_test(tc, tc_s21_atan_8);
  suite_add_tcase(s, tc);
  return (s);
}