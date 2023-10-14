#include "../tests_s21_string.h"

START_TEST(strlen_test) {
  // Test 1
  char str1[] = "";
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len1_orig = strlen(str1);
  ck_assert_uint_eq(len1, len1_orig);

  // Test 2
  char str2[] = "Hello, world!";
  s21_size_t len2 = s21_strlen(str2);
  s21_size_t len2_orig = strlen(str2);
  ck_assert_uint_eq(len2, len2_orig);

  // Test 3
  char str3[] = "     ";
  s21_size_t len3 = s21_strlen(str3);
  s21_size_t len3_orig = strlen(str3);
  ck_assert_uint_eq(len3, len3_orig);
}
END_TEST

Suite *string_funcs_strlen() {
  Suite *suite = suite_create("---string_funcs_strlen---");
  TCase *tcase = tcase_create("strlen");

  tcase_add_test(tcase, strlen_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
