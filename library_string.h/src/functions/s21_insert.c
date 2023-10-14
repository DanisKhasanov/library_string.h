#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *res = (char *)calloc((s21_strlen(str) + s21_strlen(src)), sizeof(char));
  if (start_index > s21_strlen(src)) return S21_NULL;
  s21_size_t i = 0;
  for (i = 0; i < start_index; ++i) {
    res[i] = src[i];
  }
  s21_size_t j = 0;
  for (j = 0; str[j] != '\0'; ++j) {
    res[i + j] = str[j];
  }
  for (; src[i] != '\0'; ++i) {
    res[i + j] = src[i];
  }
  return (void *)res;
}