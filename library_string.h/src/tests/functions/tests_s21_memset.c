#include "../tests_s21_string.h"

START_TEST(memset_test) {
  // Test 1
  char str1_1[21] = "Dreamteam.";
  char str1_2[21] = "Dreamteam.";

  memset(str1_1, 'X', 3);
  s21_memset(str1_2, 'X', 3);

  ck_assert_str_eq(str1_1, str1_2);

  // Test 2
  char str2_1[21] = "Dreamteam.";
  char str2_2[21] = "Dreamteam.";

  memset(str2_1, 'X', (0));
  s21_memset(str2_2, 'X', (0));

  ck_assert_str_eq(str2_1, str2_2);

  // Test 3
  char str3_1[21] = "Dreamteam.";
  char str3_2[21] = "Dreamteam.";

  memset(str3_1, 'X', 20);
  s21_memset(str3_2, 'X', 20);

  ck_assert_str_eq(str3_1, str3_2);
}
END_TEST

Suite *string_funcs_memset() {
  Suite *suite = suite_create("---string_funcs_memset---");
  TCase *tcase = tcase_create("memset");

  tcase_add_test(tcase, memset_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
