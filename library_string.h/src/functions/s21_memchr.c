#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *res = S21_NULL;
  const unsigned char *el_str = (const unsigned char *)str;
  const unsigned char el = (const unsigned char)c;
  for (s21_size_t i = 0; i < n && res == S21_NULL; i++) {
    if (el_str[i] == el) {
      res = (char *)(el_str + i);
    }
  }
  return res;
}