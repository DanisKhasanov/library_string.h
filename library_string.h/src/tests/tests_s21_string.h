#ifndef TESTS_S21_STRING_H
#define TESTS_S21_STRING_H
#define BF_SIZE 64
#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *string_funcs_memcmp();
Suite *string_funcs_strcat();
Suite *string_funcs_strncat();
Suite *string_funcs_strtok();
Suite *string_funcs_strerror();
Suite *string_funcs_strncmp();
Suite *string_funcs_memchr();
Suite *string_funcs_memmove();
Suite *string_funcs_memchr();
Suite *string_funcs_memcpy();
Suite *string_funcs_memset();
Suite *string_funcs_strcpy();
Suite *string_funcs_strlen();
Suite *string_funcs_strncpy();
Suite *string_funcs_strrchr();
Suite *string_funcs_strpbrk();
Suite *string_funcs_strstr();
Suite *string_funcs_strcspn();
Suite *string_funcs_insert();
Suite *string_funcs_trim();
Suite *string_funcs_lower();
Suite *string_funcs_upper();
Suite *s21_math_tests_create();
Suite *string_funcs_strchr();
Suite *string_funcs_strspn();
#endif