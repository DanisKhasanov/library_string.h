#include "../s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  char *p1 = (char *)str1;
  int flag1 = 0;
  while (*p1 != '\0' && !flag1) {
    char *p2 = (char *)str2;
    int flag2 = 0;
    while (*p2 != '\0' && !flag2) {
      if (*p1 == *p2) {
        res++;
        flag2++;
      }
      p2++;
      if (*p2 == '\0' && flag2 == 0) flag1 = 1;
    }
    p1++;
  }
  return res;
}