#include "../tests_s21_string.h"

START_TEST(memcpy_test) {
  // Test 1
  const char* src1 = "Kopirovanie celogo massiva.";
  char dest1_1[50];
  char dest1_2[50];

  memcpy(dest1_1, src1, strlen(src1) + 1);
  s21_memcpy(dest1_2, src1, strlen(src1) + 1);

  ck_assert_str_eq(dest1_1, dest1_2);

  // Test 2
  const char* src2 = "Kopirovanie opredellennogo kolichestva simvolov.";
  char dest2_1[50] = {0};
  char dest2_2[50] = {0};

  memcpy(dest2_1, src2, 10);
  s21_memcpy(dest2_2, src2, 10);

  ck_assert_str_eq(dest2_1, dest2_2);

  // Test 3
  const char* src3 = "Kopirovanie nulevogo kolichestva simvolov.";
  char dest3_1[50] = "Tut stroka";
  char dest3_2[50] = "Tut stroka";

  memcpy(dest3_1, src3, 0);
  s21_memcpy(dest3_2, src3, 0);

  ck_assert_str_eq(dest3_1, dest3_2);
}
END_TEST

Suite* string_funcs_memcpy() {
  Suite* suite = suite_create("---string_funcs_memcpy---");
  TCase* tcase = tcase_create("memcpy");

  tcase_add_test(tcase, memcpy_test);

  suite_add_tcase(suite, tcase);
  return suite;
}