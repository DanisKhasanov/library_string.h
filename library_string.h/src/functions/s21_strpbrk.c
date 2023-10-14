#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  const char *p1 = str1;
  const char *p2 = str2;
  for (s21_size_t i = 0; str1[i] != '\0' && res == S21_NULL; i++) {
    for (s21_size_t j = 0; str2[j] != '\0' && res == S21_NULL; j++) {
      if (p1[i] == p2[j]) res = (char *)(p1 + i);
    }
  }
  return res;
}