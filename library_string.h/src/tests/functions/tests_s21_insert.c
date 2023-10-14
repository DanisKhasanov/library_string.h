#include "../tests_s21_string.h"

START_TEST(insert_test) {
  char src[] = "bolshaya stroka (sovsem malenkoy djest stroki ne budet)";
  char str[] = " stroka pomenshe ";

  char *new_str = (char *)s21_insert(src, str, 4);
  ck_assert_str_eq(new_str,
                   "bols stroka pomenshe haya stroka (sovsem malenkoy djest "
                   "stroki ne budet)");
  if (new_str) free(new_str);
  new_str = S21_NULL;

  new_str = (char *)s21_insert(src, str, 0);
  ck_assert_str_eq(new_str,
                   " stroka pomenshe bolshaya stroka (sovsem malenkoy djest "
                   "stroki ne budet)");
  if (new_str) free(new_str);
  new_str = S21_NULL;

  new_str = (char *)s21_insert(src, str, 99999);
  ck_assert_pstr_eq(new_str, S21_NULL);
  if (new_str) free(new_str);
  new_str = S21_NULL;
}
END_TEST

Suite *string_funcs_insert() {
  Suite *suite = suite_create("---string_funcs_insert---");
  TCase *tcase = tcase_create("insert");

  tcase_add_test(tcase, insert_test);

  suite_add_tcase(suite, tcase);
  return suite;
}