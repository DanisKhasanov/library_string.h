#include "../tests_s21_string.h"

START_TEST(lower_test_1) {
  char buffer[] = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[";
  char *result = s21_to_lower(buffer);
  ck_assert_str_eq("@abcdefghijklmnopqrstuvwxyz[", result);
  free(result);
  result = S21_NULL;
}
END_TEST

START_TEST(lower_test_2) {
  char *buffer = NULL;
  char *result = s21_to_lower(buffer);
  ck_assert_ptr_null(result);
  free(result);
  result = S21_NULL;
}
END_TEST

START_TEST(lower_test_3) {
  char buffer[] = "@ABC324 5435DEF@#$^ &*(GHIJK**+++* //LMNOPQRSTUVWXYZ[";
  char *result = s21_to_lower(buffer);
  ck_assert_str_eq("@abc324 5435def@#$^ &*(ghijk**+++* //lmnopqrstuvwxyz[",
                   result);
  free(result);
  result = S21_NULL;
}
END_TEST

Suite *string_funcs_lower() {
  Suite *suite = suite_create("---string_funcs_lower---");
  TCase *tcase = tcase_create("lower");

  tcase_add_test(tcase, lower_test_1);
  tcase_add_test(tcase, lower_test_2);
  tcase_add_test(tcase, lower_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}