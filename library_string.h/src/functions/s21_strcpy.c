#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *data = dest;
  while (*src != '\0') {
    *data = *src;
    data++;
    src++;
  }
  *data = '\0';

  return dest;
}