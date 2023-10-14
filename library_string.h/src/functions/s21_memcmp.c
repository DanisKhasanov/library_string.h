#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *p1 = str1, *p2 = str2;
  int difference = 0;
  for (size_t i = 0; i < n; ++i) {
    difference = *p1 - *p2;
    if (difference != 0) {
      break;
    }
    ++p1, ++p2;
  }
  return difference;
}
