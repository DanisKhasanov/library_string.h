#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *el_del = (char *)trim_chars;
  char *start = (char *)src;
  int flag1 = 0;
  while (*start != '\0' && !flag1) {
    for (; *el_del != *start; el_del++) {
      if (*el_del == '\0') flag1 = 1;
    }
    if (!flag1) {
      start++;
      el_del = (char *)trim_chars;
    }
  }
  el_del = (char *)trim_chars;

  char *end = (char *)(src + s21_strlen(src)) - 1;
  int flag2 = 0;
  while (end != start && !flag2) {
    for (; *el_del != *end; el_del++) {
      if (*el_del == '\0') flag2 = 1;
    }
    if (!flag2) {
      end = end - 1;
      el_del = (char *)trim_chars;
    }
  }

  char *res = S21_NULL;

  if (start < end) {
    res = (char *)calloc((end - start + 1), sizeof(char));
    for (s21_size_t i = 0; start <= end; i++, start++) {
      res[i] = *start;
    }
    res[end - start] = '\0';
  }
  return res;
}
