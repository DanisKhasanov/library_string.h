#include "../tests_s21_string.h"

START_TEST(strpbrk_test_0) {
  char* str1 = "Zapomnite tvary ya ne volk";
  char* str2 = "k";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_1) {
  char* str1 = "Zapomnite tvary ya ne volk";
  char* str2 = "Z";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_2) {
  char* str1 = "Esly ti odin protiv tolpi tebe *****";
  char* str2 = "";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_3) {
  char* str1 = "";
  char* str2 = "cant find in non symbols str";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test_4) {
  char* str1 = "how  strpbrk react on";
  char* str2 = "\0";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite* string_funcs_strpbrk() {
  Suite* suite = suite_create("---string_funcs_strpbrk---");
  TCase* tcase = tcase_create("strpbrk");

  tcase_add_test(tcase, strpbrk_test_0);
  tcase_add_test(tcase, strpbrk_test_1);
  tcase_add_test(tcase, strpbrk_test_2);
  tcase_add_test(tcase, strpbrk_test_3);
  tcase_add_test(tcase, strpbrk_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}