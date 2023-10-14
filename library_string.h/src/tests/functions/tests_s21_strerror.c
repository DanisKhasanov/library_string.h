#include "../tests_s21_string.h"

START_TEST(test_s21_strerror_0) {
  int err_num = 7;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(test_s21_strerror_1) {
  int err_num = 134;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

Suite *string_funcs_strerror() {
  Suite *suite = suite_create("---string_funcs_strerror---");
  TCase *tcase = tcase_create("strerror");

  tcase_add_test(tcase, test_s21_strerror_0);
  tcase_add_test(tcase, test_s21_strerror_1);

  suite_add_tcase(suite, tcase);
  return suite;
}