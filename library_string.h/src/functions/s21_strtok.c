#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *step;
  char *nashel = S21_NULL;

  str = (str == S21_NULL) ? step : str;

  if (str != S21_NULL && (nashel = s21_strpbrk(str, delim)) != S21_NULL) {
    step = nashel + 1 + s21_strspn(nashel + 1, delim);
    *(nashel) = '\0';
  } else {
    step = S21_NULL;
  }

  if (step != S21_NULL) {
    s21_size_t tempLen = s21_strlen(nashel + 1);
    if (tempLen == 0) {
      step = S21_NULL;
    }
  }

  return str;
}
