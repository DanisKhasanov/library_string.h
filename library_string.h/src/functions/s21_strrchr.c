#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  char *el_str = (char *)str;
  const unsigned char el = (const unsigned char)c;
  s21_size_t i = 0;
  for (i = 0; el_str[i] != '\0'; i++) {
    if (el_str[i] == el) {
      res = el_str + i;
    }
    if (el == '\0') {
      res = el_str + i + 1;
    }
  }
  return res;
}