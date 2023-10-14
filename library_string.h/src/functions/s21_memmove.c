#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (d < s) {
    for (s21_size_t i = 0; i < n; i++) d[i] = s[i];
  } else {
    for (s21_size_t i = n; i != 0; i--) d[i - 1] = s[i - 1];
  }

  return dest;
}