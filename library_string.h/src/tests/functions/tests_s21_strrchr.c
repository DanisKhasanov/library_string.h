#include "../tests_s21_string.h"

START_TEST(strrchr_test_0) {
  char *str = "Vsymbol on the left side";
  int c = 'V';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_test_1) {
  char *str = "symbol on the right sideV";
  int c = 'V';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_test_2) {
  char *str = "a V lot V of Vchar";
  int c = 'V';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_test_3) {
  char *str = "a V lot \0 V of Vchar";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_test_4) {
  char *str = "";
  int c = 'n';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *string_funcs_strrchr() {
  Suite *suite = suite_create("---string_funcs_strrchr---");
  TCase *tcase = tcase_create("strrchr");

  tcase_add_test(tcase, strrchr_test_0);
  tcase_add_test(tcase, strrchr_test_1);
  tcase_add_test(tcase, strrchr_test_2);
  tcase_add_test(tcase, strrchr_test_3);
  tcase_add_test(tcase, strrchr_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}