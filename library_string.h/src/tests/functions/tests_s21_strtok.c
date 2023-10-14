#include "../tests_s21_string.h"

START_TEST(test_s21_strtok_0) {
  char str1[100] = "dva+odin+tri+sem'";
  char str11[100] = "dva+odin+tri+sem'";
  char *str2 = "+";
  char *tok = S21_NULL;
  char *tokO = S21_NULL;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != S21_NULL) {
    ck_assert_pstr_eq(tok, tokO);
    tok = strtok(S21_NULL, str2);
    tokO = s21_strtok(S21_NULL, str2);
  }
}
END_TEST

START_TEST(test_s21_strtok_1) {
  char str1[100] = "kak don vi don menya don nashli don ";
  char str11[100] = "kak don vi don menya don nashli don ";
  char str2[10] = "don";
  char *tok;
  char *tokO;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != S21_NULL) {
    ck_assert_str_eq(tok, tokO);
    tok = strtok(S21_NULL, str2);
    tokO = s21_strtok(S21_NULL, str2);
  }
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str1[100] = "test1/test2/test3/test4";
  char str11[100] = "test1/test2/test3/test4";
  char str2[10] = "/";
  char *tok;
  char *tokO;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != S21_NULL) {
    ck_assert_str_eq(tok, tokO);
    tok = strtok(S21_NULL, str2);
    tokO = s21_strtok(S21_NULL, str2);
  }
}
END_TEST

Suite *string_funcs_strtok() {
  Suite *suite = suite_create("---string_funcs_strtok---");
  TCase *tcase = tcase_create("strtok");

  tcase_add_test(tcase, test_s21_strtok_0);
  tcase_add_test(tcase, test_s21_strtok_1);
  tcase_add_test(tcase, test_s21_strtok_2);

  suite_add_tcase(suite, tcase);
  return suite;
}
