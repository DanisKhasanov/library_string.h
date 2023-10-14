#include "../tests_s21_string.h"

START_TEST(memmove_test) {
  char src1[] = "This is a test string.";
  char src2[] = "This is a test string.";

  memmove(src1 + 10, src1 + 5, 10);
  s21_memmove(src2 + 10, src2 + 5, 10);

  ck_assert_str_eq(src1, src2);
}
END_TEST

Suite *string_funcs_memmove() {
  Suite *suite = suite_create("---string_funcs_memmove---");
  TCase *tcase = tcase_create("memmove");

  tcase_add_test(tcase, memmove_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
