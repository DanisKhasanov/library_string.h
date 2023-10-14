#include "../tests_s21_string.h"

START_TEST(strcpy_test) {
  // Test 1
  const char *src1 = "Eto stroka dlya testa.";
  char dest1_1[50];
  char dest1_2[50];

  strcpy(dest1_1, src1);
  s21_strcpy(dest1_2, src1);

  ck_assert_str_eq(dest1_1, dest1_2);

  // Test 2
  const char *src2 = "";
  char dest2_1[50] = "Tut stroka";
  char dest2_2[50] = "Tut stroka";

  strcpy(dest2_1, src2);
  s21_strcpy(dest2_2, src2);

  ck_assert_str_eq(dest2_1, dest2_2);
}
END_TEST

Suite *string_funcs_strcpy() {
  Suite *suite = suite_create("---string_funcs_strcpy---");
  TCase *tcase = tcase_create("strcpy");

  tcase_add_test(tcase, strcpy_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
