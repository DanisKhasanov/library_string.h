#include "../tests_s21_string.h"

START_TEST(strspn_test_0) {
  char *str1 = "standart situation";
  char *str2 = "stan";
  ck_assert_uint_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test_1) {
  char *str1 = "standart situation";
  char *str2 = "s";
  ck_assert_uint_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test_2) {
  char *str1 = "find nothing";
  char *str2 = "";
  ck_assert_uint_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test_3) {
  char *str1 = "";
  char *str2 = "hehe";
  ck_assert_uint_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test_4) {
  char *str1 = "\0with term zero dherherthrh";
  char *str2 = "\0";
  ck_assert_uint_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

Suite *string_funcs_strspn() {
  Suite *suite = suite_create("---string_funcs_strspn---");
  TCase *tcase = tcase_create("strspn");

  tcase_add_test(tcase, strspn_test_0);
  tcase_add_test(tcase, strspn_test_1);
  tcase_add_test(tcase, strspn_test_2);
  tcase_add_test(tcase, strspn_test_3);
  tcase_add_test(tcase, strspn_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}