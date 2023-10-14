#include "../tests_s21_string.h"

START_TEST(upper_test_1) {
  char buffer[] = "`abcdefghijklmnopqrstuvwxyz{";
  char *result = s21_to_upper(buffer);
  ck_assert_str_eq("`ABCDEFGHIJKLMNOPQRSTUVWXYZ{", result);
  free(result);
}
END_TEST

START_TEST(upper_test_2) {
  char *buffer = NULL;
  char *result = s21_to_upper(buffer);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(upper_test_3) {
  char buffer[] = "`abcdefg341hijkl mno pqr654!)(_st-*/uvwxyz{";
  char *result = s21_to_upper(buffer);
  ck_assert_str_eq("`ABCDEFG341HIJKL MNO PQR654!)(_ST-*/UVWXYZ{", result);
  free(result);
}
END_TEST

Suite *string_funcs_upper() {
  Suite *suite = suite_create("---string_funcs_upper---");
  TCase *tcase = tcase_create("upper");

  tcase_add_test(tcase, upper_test_1);
  tcase_add_test(tcase, upper_test_2);
  tcase_add_test(tcase, upper_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}
