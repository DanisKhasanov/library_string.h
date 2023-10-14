#include "../tests_s21_string.h"

START_TEST(memchr_test) {
  char *s = "This is test";

  ck_assert_ptr_eq(s21_memchr("123453", '3', 10), memchr("123453", '3', 10));
  ck_assert_ptr_eq(s21_memchr(s, 's', 0), memchr(s, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s, 's', 2), memchr(s, 's', 2));
  ck_assert_ptr_eq(s21_memchr(s, 's', 40), memchr(s, 's', 40));
  ck_assert_ptr_eq(s21_memchr(s, 'u', 55), memchr(s, 'u', 55));
  ck_assert_ptr_eq(s21_memchr(s, 'u', 64), memchr(s, 'u', 64));
}
END_TEST

Suite *string_funcs_memchr() {
  Suite *suite = suite_create("---string_funcs_memchr---");
  TCase *tcase = tcase_create("memchr");

  tcase_add_test(tcase, memchr_test);

  suite_add_tcase(suite, tcase);
  return suite;
}