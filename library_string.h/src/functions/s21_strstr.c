#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *p1 = (char *)haystack;
  if (*needle == '\0') return p1;
  char *res = S21_NULL;
  while (*p1 != '\0' && res == S21_NULL) {
    if (*p1 == *needle) {
      res = p1;
      char *p2 = (char *)needle;
      while (*p2 != '\0') {
        if (*p1 != *p2) {
          res = S21_NULL;
        }
        p2++;
        p1++;
      }
    }
    p1++;
  }
  return res;
}