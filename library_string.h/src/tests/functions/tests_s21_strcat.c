#include "../tests_s21_string.h"

START_TEST(test_s21_strcat_0) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " govnocoder";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str11, str2));
}
END_TEST

START_TEST(test_s21_strcat_4) {
  char str1[100] = {0};
  char str11[100] = {0};
  char str2[] = " govnocoder";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str11, str2));
}
END_TEST

Suite *string_funcs_strcat() {
  Suite *suite = suite_create("---string_funcs_strcat---");
  TCase *tcase = tcase_create("strcat");

  tcase_add_test(tcase, test_s21_strcat_0);
  tcase_add_test(tcase, test_s21_strcat_4);

  suite_add_tcase(suite, tcase);
  return suite;
}