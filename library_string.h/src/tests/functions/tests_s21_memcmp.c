#include "../tests_s21_string.h"

START_TEST(test_s21_memcmp_0) {
  char str1_1[128] = {0};
  for (int i = 0; i < 11; i++) {
    str1_1[i] = 'a' + i;
  }
  char str2_1[128] = {0};
  for (int i = 0; i < 11; i++) {
    str2_1[i] = 'a' + i;
  }
  str1_1[10] = '\0';
  str2_1[10] = '\0';
  size_t n = 33;
  ck_assert_int_eq(s21_memcmp(str1_1, str2_1, n), memcmp(str1_1, str2_1, n));
}
END_TEST

START_TEST(test_s21_memcmp_1) {
  char *str1_2 = malloc(10 * sizeof(char));
  if (str1_2) {
    for (int i = 0; i < 10; i++) {
      str1_2[i] = i;
    }
    char *str2_2 = malloc(7 * sizeof(char));
    if (str2_2) {
      for (int i = 0; i < 7; i++) {
        str2_2[i] = i;
      }

      size_t n = 7;
      ck_assert_int_eq(s21_memcmp(str1_2, str2_2, n),
                       memcmp(str1_2, str2_2, n));
      free(str2_2);
    }
    free(str1_2);
  }
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char *str1 = "kto-to videl chto-to";
  char *str2 = "ya nichego ne videl";
  size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char *str1 = "ya nichego ne videl";
  char *str2 = "kto-to videl chto-to";
  size_t n = 100;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char *str1 = "poterjali nol'";
  char *strd1_3 = calloc(1000, 1);

  if (strd1_3) {
    char *strd2_3 = calloc(1000, 1);
    if (strd2_3) {
      strd1_3 = s21_strcpy(strd1_3, str1);
      strd1_3[s21_strlen(strd1_3)] = ')';
      char *str2 = "poterjali nol'";

      strd2_3 = s21_strcpy(strd2_3, str2);
      strd2_3[s21_strlen(strd2_3)] = ')';
      size_t n = 100;
      ck_assert_int_eq(s21_memcmp(strd1_3, strd2_3, n),
                       memcmp(strd1_3, strd2_3, n));

      free(strd2_3);
    }
    free(strd1_3);
  }
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char *str1 = "a i b sideli na trube";
  char *str2 = "qwerty";
  size_t n = 100;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_7) {
  char *str1 = "big data KEKW";
  char *strd1_4 = calloc(1000, 1);
  if (strd1_4) {
    char *strd2_4 = calloc(1000, 1);
    if (strd2_4) {
      strd1_4 = strcpy(strd1_4, str1);
      char *str2 = "bid data KEKW";
      strd2_4 = strcpy(strd2_4, str2);
      unsigned long long n = 674;
      ck_assert_int_eq(s21_memcmp(strd1_4, strd2_4, n),
                       memcmp(strd1_4, strd2_4, n));

      free(strd2_4);
    }
    free(strd1_4);
  }
}
END_TEST

START_TEST(test_s21_memcmp_9) {
  double str1[] = {1000.111111111, 1000.2, 1000.3};
  double str2[] = {1000.111111111, 2000.111111111, 3000};
  unsigned long long n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *string_funcs_memcmp() {
  Suite *suite = suite_create("---string_funcs_memcmp---");
  TCase *tcase = tcase_create("memcmp");

  tcase_add_test(tcase, test_s21_memcmp_0);
  tcase_add_test(tcase, test_s21_memcmp_1);
  tcase_add_test(tcase, test_s21_memcmp_2);
  tcase_add_test(tcase, test_s21_memcmp_3);
  tcase_add_test(tcase, test_s21_memcmp_4);
  tcase_add_test(tcase, test_s21_memcmp_5);
  tcase_add_test(tcase, test_s21_memcmp_7);
  tcase_add_test(tcase, test_s21_memcmp_9);

  suite_add_tcase(suite, tcase);
  return suite;
}