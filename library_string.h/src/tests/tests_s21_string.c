#include "tests_s21_string.h"

int main() {
  Suite *s21_string_tests[] = {string_funcs_strncat(),  string_funcs_memcmp(),
                               string_funcs_strcat(),   string_funcs_strerror(),
                               string_funcs_strtok(),   string_funcs_strncmp(),
                               string_funcs_memchr(),   string_funcs_memmove(),
                               string_funcs_memchr(),   string_funcs_memcpy(),
                               string_funcs_memset(),   string_funcs_strcpy(),
                               string_funcs_strlen(),   string_funcs_strncpy(),
                               string_funcs_strrchr(),  string_funcs_strpbrk(),
                               string_funcs_strstr(),   string_funcs_strcspn(),
                               string_funcs_insert(),   string_funcs_trim(),
                               string_funcs_lower(),    string_funcs_upper(),
                               s21_math_tests_create(), string_funcs_strchr(),
                               string_funcs_strspn(),   NULL};

  int failed = 0;
  for (int i = 0; s21_string_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_tests[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}