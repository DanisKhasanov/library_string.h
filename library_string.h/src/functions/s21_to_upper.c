#include "../s21_string.h"

char *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  size_t len = s21_strlen(str);
  char *result = (char *)malloc((len + 1) * sizeof(char));
  if (result == S21_NULL) {
    result = S21_NULL;
  } else {
    for (size_t i = 0; i < len; i++) {
      result[i] = touppersimple(str[i]);
    }
    result[len] = '\0';
  }
  return result;
}

int touppersimple(int c) {
  if (c >= 97 && c <= 122) {
    return c - 32;
  }
  return c;
}