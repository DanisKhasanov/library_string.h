#include "../s21_string.h"

void *s21_memcpy(void *s21_destination, const void *s21_source, size_t num) {
  char *data_res = s21_destination;
  const char *data_src = s21_source;

  for (s21_size_t i = 0; i < num; i++) {
    data_res[i] = data_src[i];
  }

  return data_res;
}