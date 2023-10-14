#include "../tests_s21_string.h"

START_TEST(strncpy_test) {
  // Test 1
  const char* src1 = "n menshe dliny src.";
  char dest1_1[30] = {0};
  char dest1_2[30] = {0};

  strncpy(dest1_1, src1, 10);
  s21_strncpy(dest1_2, src1, 10);

  ck_assert_str_eq(dest1_1, dest1_2);

  // Test 2
  const char* src2 = "korotkaya stroka";
  char dest2_1[30] = {0};
  char dest2_2[30] = {0};

  strncpy(dest2_1, src2, 20);
  s21_strncpy(dest2_2, src2, 20);

  ck_assert_str_eq(dest2_1, dest2_2);

  // Test 3
  const char* src3 = "esche stroka dlya testirovanya.";
  char dest3_1[30] = "tipa dannye";
  char dest3_2[30] = "tipa dannye";

  strncpy(dest3_1, src3, 0);
  s21_strncpy(dest3_2, src3, 0);

  ck_assert_str_eq(dest3_1, dest3_2);
}
END_TEST

Suite* string_funcs_strncpy() {
  Suite* suite = suite_create("---string_funcs_strncpy---");
  TCase* tcase = tcase_create("strncpy");

  tcase_add_test(tcase, strncpy_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
