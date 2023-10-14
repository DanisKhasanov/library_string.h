#include "../s21_string.h"

char *s21_strerror(int errnum) {
  static char resultError[128];
  if (errnum <= 0 || errnum > MAX_ERRORS_NUMBERS) {
    s21_sprintf(resultError, "%s%d", "Unknown error: ", errnum);
  } else {
    char allErrors[MAX_ERRORS_NUMBERS][128] = ERRORS;
    s21_strcpy(resultError, allErrors[errnum]);
  }
  return resultError;
}
