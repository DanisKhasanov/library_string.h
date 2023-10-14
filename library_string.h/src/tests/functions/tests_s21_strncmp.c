#include "../tests_s21_string.h"

START_TEST(test_s21_strncmp_0) {
  char *str1 = "Mom was washed the dishes";
  char *str2 = "Mom was";
  size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str1[] = "Lora Palmer";
  char str2[] = "Lora Aboba";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *string_funcs_strncmp() {
  Suite *suite = suite_create("---string_funcs_strncmp---");
  TCase *tcase = tcase_create("strncmp");

  tcase_add_test(tcase, test_s21_strncmp_0);
  tcase_add_test(tcase, test_s21_strncmp_2);

  suite_add_tcase(suite, tcase);
  return suite;
}