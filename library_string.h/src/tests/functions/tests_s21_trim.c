#include "../tests_s21_string.h"

START_TEST(trim_test) {
  char src[] =
      "     fghjgfhjbolshaya stroka (sovsem malenkoy djest stroki ne "
      "budet)fghjfghjfghj     ";
  char str[] = "fgh j";

  char *new_str = (char *)s21_trim(src, str);
  ck_assert_str_eq(new_str,
                   "bolshaya stroka (sovsem malenkoy djest stroki ne budet)");
  if (new_str) free(new_str);
  new_str = S21_NULL;

  char src1[] =
      "     fghjgfhjbolshaya stroka (sovsem malenkoy djest stroki ne "
      "budet)fghjfghjfghj     ";
  char str1[] =
      "    fghjgfhjbolshaya stroka (sovsem malenkoy djest stroki ne "
      "budet)fghjfghjfghj     ";

  new_str = (char *)s21_trim(src1, str1);
  ck_assert_ptr_null(new_str);
  if (new_str) free(new_str);
  new_str = S21_NULL;

  char src2[] = "";
  char str2[] =
      "    fghjgfhjbolshaya stroka (sovsem malenkoy djest stroki ne "
      "budet)fghjfghjfghj     ";

  new_str = (char *)s21_trim(src2, str2);
  ck_assert_ptr_null(new_str);
  if (new_str) free(new_str);
  new_str = S21_NULL;
}
END_TEST

Suite *string_funcs_trim() {
  Suite *suite = suite_create("---string_funcs_trim---");
  TCase *tcase = tcase_create("trim");

  tcase_add_test(tcase, trim_test);

  suite_add_tcase(suite, tcase);
  return suite;
}