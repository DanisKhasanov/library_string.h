#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  const unsigned char *el_str = (const unsigned char *)str;
  const unsigned char el = (const unsigned char)c;
  for (s21_size_t i = 0; el_str[i] != '\0' && res == S21_NULL; i++) {
    if (el_str[i] == el) {
      res = (char *)(el_str + i);
    }
  }
  if (c == '\0') res = "\0";
  return res;
}