#include "../tests_s21_string.h"

START_TEST(strstr_test_0) {
  char* str1 = "Zapomnite tvary ya ne volk";
  char* str2 = "volk";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_1) {
  char* str1 = "Zapomnite tvary ya ne volk";
  char* str2 = "Zapomnite";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_2) {
  char* str1 = "Esly ti odin protiv tolpi tebe *****";
  char* str2 = "";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_3) {
  char* str1 = "";
  char* str2 = "cant find in non symbols str";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test_4) {
  char* str1 = "how \0HI strpbrk react on";
  char* str2 = "\0HI";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite* string_funcs_strstr() {
  Suite* suite = suite_create("---string_funcs_strstr---");
  TCase* tcase = tcase_create("strstr");

  tcase_add_test(tcase, strstr_test_0);
  tcase_add_test(tcase, strstr_test_1);
  tcase_add_test(tcase, strstr_test_2);
  tcase_add_test(tcase, strstr_test_3);
  tcase_add_test(tcase, strstr_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}