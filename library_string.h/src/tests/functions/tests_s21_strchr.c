#include "../tests_s21_string.h"

START_TEST(strchr_test_0) {
  char *str = "";
  char ch = 'i';
  ck_assert_ptr_null(s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_test_1) {
  char *str = "memchr test (find first symbol)";
  char ch = 'i';
  ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_test_2) {
  char *str = "memchr test (find first symbol)";
  char ch = 'x';
  ck_assert_ptr_null(s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_test_3) {
  char *str = "hello therel";
  char ch = 'l';
  ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_test_4) {
  char *str = "123 \0 4533 hehe ";
  char ch = '\0';
  ck_assert_str_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

Suite *string_funcs_strchr() {
  Suite *suite = suite_create("---string_funcs_strchr---");
  TCase *tcase = tcase_create("strchr");

  tcase_add_test(tcase, strchr_test_0);
  tcase_add_test(tcase, strchr_test_1);
  tcase_add_test(tcase, strchr_test_2);
  tcase_add_test(tcase, strchr_test_3);
  tcase_add_test(tcase, strchr_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
