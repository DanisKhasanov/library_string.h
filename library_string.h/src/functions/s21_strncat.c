#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *all_mass = dest + s21_strlen(dest);
  size_t max_size = s21_strlen(dest) + s21_strlen(src);
  size_t i = 0;
  while (i < n && i < max_size) {
    *all_mass = *src;
    all_mass++;
    src++;
    i++;
  }
  return dest;
}
