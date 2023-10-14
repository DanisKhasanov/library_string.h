#include "../tests_s21_string.h"

START_TEST(test_s21_strncat_0) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " govnocoder";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_1) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " molodec SHUTKA";
  s21_size_t n = 30000;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " Za rabotoi";
  s21_size_t n = -1;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char str1[100] = "Chris\0 Torek";
  char str11[100] = "Chris\0 Torek";
  char str2[] = " plohoicoder";
  s21_size_t n = 7;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char str1[100] = "Chris\0 Torek";
  char str11[100] = "Chris\0 Torek";
  char str2[] = " plohoi\0coder";
  s21_size_t n = 100;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char str1[100] = "nichego";
  char str11[100] = "nichego";
  char str2[] = "ne proishodit";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

Suite *string_funcs_strncat() {
  Suite *suite = suite_create("---string_funcs_strncat---");
  TCase *tcase = tcase_create("strncat");

  tcase_add_test(tcase, test_s21_strncat_0);
  tcase_add_test(tcase, test_s21_strncat_1);
  tcase_add_test(tcase, test_s21_strncat_2);
  tcase_add_test(tcase, test_s21_strncat_3);
  tcase_add_test(tcase, test_s21_strncat_4);
  tcase_add_test(tcase, test_s21_strncat_5);

  suite_add_tcase(suite, tcase);
  return suite;
}