#include "../tests_s21_string.h"

START_TEST(sprintf_test) {
  /*==================  specifier d   ===========================*/
  char str[100] = {'\0'};
  char str_copy[100] = {'\0'};

  sprintf(str, "%.d", 4);
  s21_sprintf(str_copy, "%.d", 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%*d", 5, 4);
  s21_sprintf(str_copy, "%*d", 5, 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "% d", 4);
  s21_sprintf(str_copy, "% d", 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%.5d", 0);
  s21_sprintf(str_copy, "%.5d", 0);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%.*d", 5, 4);
  s21_sprintf(str_copy, "%.*d", 5, 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%.10d\n", 4);
  s21_sprintf(str_copy, "%.10d\n", 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%d\n", -4);
  s21_sprintf(str_copy, "%d\n", -4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%-+10d\n", 4);
  s21_sprintf(str_copy, "%-+10d\n", 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%-10d\n", -4);
  s21_sprintf(str_copy, "%-10d\n", -4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%+10d\n", 4);
  s21_sprintf(str_copy, "%+10d\n", 4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%+10d\n", -4);
  s21_sprintf(str_copy, "%+10d\n", -4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%+10.5d\n", -4);
  s21_sprintf(str_copy, "%+10.5d\n", -4);
  ck_assert_str_eq(str, str_copy);

  long int var_long = 100;
  sprintf(str, "%ld\n", var_long);
  s21_sprintf(str_copy, "%ld\n", var_long);
  ck_assert_str_eq(str, str_copy);

  short var_short = 123;
  sprintf(str, "%hd\n", var_short);
  s21_sprintf(str_copy, "%hd\n", var_short);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%+10.5d%%\n", -4);
  s21_sprintf(str_copy, "%+10.5d%%\n", -4);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%05d\n", 0);
  s21_sprintf(str_copy, "%05d\n", 0);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%0+d\n", 5);
  s21_sprintf(str_copy, "%0+d\n", 5);
  ck_assert_str_eq(str, str_copy);

  sprintf(str, "%0+d\n", -5);
  s21_sprintf(str_copy, "%0+d\n", -5);
  ck_assert_str_eq(str, str_copy);

  /*==================  specifier s   ===========================*/
  char str3[100] = {'\0'};
  char str4[100] = {'\0'};

  sprintf(str3, "%s", "Hello");
  s21_sprintf(str4, "%s", "Hello");
  ck_assert_str_eq(str3, str4);

  sprintf(str3, "%.1s", "Hello");
  s21_sprintf(str4, "%.1s", "Hello");
  ck_assert_str_eq(str3, str4);

  sprintf(str3, "%7s", "Hello");
  s21_sprintf(str4, "%7s", "Hello");
  ck_assert_str_eq(str3, str4);

  sprintf(str3, "%-10s", "Hello");
  s21_sprintf(str4, "%-10s", "Hello");
  ck_assert_str_eq(str3, str4);

  /*==================  specifier c   ===========================*/
  char str5[100] = {'\0'};
  char str6[100] = {'\0'};

  sprintf(str5, "%1c %c", 'H', 'z');
  s21_sprintf(str6, "%1c %c", 'H', 'z');
  ck_assert_str_eq(str5, str6);

  sprintf(str5, "%c %c", 'H', 'z');
  s21_sprintf(str6, "%c %c", 'H', 'z');
  ck_assert_str_eq(str5, str6);

  sprintf(str5, "%-5c", 'H');
  s21_sprintf(str6, "%-5c", 'H');
  ck_assert_str_eq(str5, str6);

  sprintf(str5, "%10c %2c", 'H', 'z');
  s21_sprintf(str6, "%10c %2c", 'H', 'z');
  ck_assert_str_eq(str5, str6);

  sprintf(str5, "%-1c %-c", 'H', 'z');
  s21_sprintf(str6, "%-1c %-c", 'H', 'z');
  ck_assert_str_eq(str5, str6);

  /*==================  specifier f   ===========================*/

  char str7[100] = {'\0'};
  char str8[100] = {'\0'};

  sprintf(str7, "%12.16f %10.17f", 100000000000.14, 100000000000.14);
  s21_sprintf(str8, "%12.16f %10.17f", 100000000000.14, 100000000000.14);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%f", 100000.4);
  s21_sprintf(str8, "%f", 100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%.16f", -100000.4);
  s21_sprintf(str8, "%.16f", -100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%-1f", 100000.4);
  s21_sprintf(str8, "%-1f", 100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%f", -100000.4);
  s21_sprintf(str8, "%f", -100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%+f %+f", -100000.4, 1000.231);
  s21_sprintf(str8, "%+f %+f", -100000.4, 1000.231);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%-20f", 100000.4);
  s21_sprintf(str8, "%-20f", 100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%-+20f", 100000.4);
  s21_sprintf(str8, "%-+20f", 100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%-20f", -100000.4);
  s21_sprintf(str8, "%-20f", -100000.4);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%+20f", 100000.4);
  s21_sprintf(str8, "%+20f", 100000.4);
  ck_assert_str_eq(str7, str8);

  long double num = 3.14159265358;
  sprintf(str7, "%Lf", num);
  s21_sprintf(str8, "%Lf", num);
  ck_assert_str_eq(str7, str8);

  sprintf(str7, "%+20f", -100000.4);
  s21_sprintf(str8, "%+20f", -100000.4);
  ck_assert_str_eq(str7, str8);
  /*==================  specifier u   ===========================*/

  char str9[100] = {'\0'};
  char str10[100] = {'\0'};

  sprintf(str9, "%.0u", 0);
  s21_sprintf(str10, "%.0u", 0);
  ck_assert_str_eq(str, str_copy);

  sprintf(str9, "%.5u\n", 4);
  s21_sprintf(str10, "%.5u\n", 4);
  ck_assert_str_eq(str9, str10);

  sprintf(str9, "%5u\n", 4);
  s21_sprintf(str10, "%5u\n", 4);
  ck_assert_str_eq(str9, str10);

  sprintf(str9, "%10.5u\n", 4);
  s21_sprintf(str10, "%10.5u\n", 4);
  ck_assert_str_eq(str9, str10);

  sprintf(str9, "%-10u\n", 421);
  s21_sprintf(str10, "%-10u\n", 421);
  ck_assert_str_eq(str9, str10);

  short unsigned key_h_u = 421;
  sprintf(str9, "%-10hu\n", key_h_u);
  s21_sprintf(str10, "%-10hu\n", key_h_u);
  ck_assert_str_eq(str9, str10);

  long unsigned key_l_u = 421;
  sprintf(str9, "%-10lu\n", key_l_u);
  s21_sprintf(str10, "%-10lu\n", key_l_u);
  ck_assert_str_eq(str9, str10);

  /*==================  specifier o   ===========================*/
  char str11[100] = {'\0'};
  char str12[100] = {'\0'};

  sprintf(str11, "%#2.5o%%\n", 4);
  s21_sprintf(str12, "%#2.5o%%\n", 4);
  ck_assert_str_eq(str11, str12);

  sprintf(str11, "%10.5o%%\n", 4);
  s21_sprintf(str12, "%10.5o%%\n", 4);
  ck_assert_str_eq(str11, str12);

  sprintf(str11, "%-10o\n", 421);
  s21_sprintf(str12, "%-10o\n", 421);
  ck_assert_str_eq(str11, str12);

  short unsigned key_h_o = 421;
  sprintf(str11, "%-10ho\n", key_h_o);
  s21_sprintf(str12, "%-10ho\n", key_h_o);
  ck_assert_str_eq(str11, str12);

  long unsigned key_l_o = 421;
  sprintf(str11, "%#-10lo%%\n", key_l_o);
  s21_sprintf(str12, "%-#10lo%%\n", key_l_o);
  ck_assert_str_eq(str11, str12);

  /*==================  specifier x X   ===========================*/

  char str13[100] = {'\0'};
  char str14[100] = {'\0'};

  sprintf(str13, "%2.5x\n", 4);
  s21_sprintf(str14, "%2.5x\n", 4);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%10.5x\n", 4);
  s21_sprintf(str14, "%10.5x\n", 4);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%-10x\n", 421);
  s21_sprintf(str14, "%-10x\n", 421);
  ck_assert_str_eq(str13, str14);

  short unsigned key_h_xX = 421;
  sprintf(str13, "%-10hx\n", key_h_xX);
  s21_sprintf(str14, "%-10hx\n", key_h_xX);
  ck_assert_str_eq(str13, str14);

  long unsigned key_l_xX = 421;
  sprintf(str13, "%#-10lx\n", key_l_xX);
  s21_sprintf(str14, "%-#10lx\n", key_l_xX);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%2.5X\n", 4);
  s21_sprintf(str14, "%2.5X\n", 4);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%10.5X\n", 4);
  s21_sprintf(str14, "%10.5X\n", 4);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%#-10X\n", 421);
  s21_sprintf(str14, "%#-10X\n", 421);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%-10hX\n", key_h_xX);
  s21_sprintf(str14, "%-10hX\n", key_h_xX);
  ck_assert_str_eq(str13, str14);

  sprintf(str13, "%-10lX\n", key_l_xX);
  s21_sprintf(str14, "%-10lX\n", key_l_xX);
  ck_assert_str_eq(str13, str14);

  /*==================  specifier p  ===========================*/
  char str15[100] = {'\0'};
  char str16[100] = {'\0'};

  char* format = "p";
  sprintf(str15, "%p", format);
  s21_sprintf(str16, "%p", format);
  ck_assert_str_eq(str15, str16);

  char* format1 = "15p";
  sprintf(str15, "%p", format1);
  s21_sprintf(str16, "%p", format1);
  ck_assert_str_eq(str15, str16);

  char* format2 = ".5p";
  sprintf(str15, "%p", format2);
  s21_sprintf(str16, "%p", format2);
  ck_assert_str_eq(str15, str16);

  /*==================  specifier e E   ===========================*/

  char str17[100] = {'\0'};
  char str18[100] = {'\0'};
  long double val = 15.35;
  long double val1 = 15.0000035;
  long double val2 = 15.00000000000000035;
  long double val3 = -15.35;

  sprintf(str17, "%e", 0.0000123);
  s21_sprintf(str18, "%e", 0.0000123);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%#.16Le\n", val);
  s21_sprintf(str18, "%#.16Le\n", val);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.0Le\n", val);
  s21_sprintf(str18, "%.0Le\n", val);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.Le\n", val1);
  s21_sprintf(str18, "%.Le\n", val1);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.15Le\n", val2);
  s21_sprintf(str18, "%.15Le\n", val2);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%10.16Le\n", val3);
  s21_sprintf(str18, "%10.16Le\n", val3);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%+10.6Le\n", val3);
  s21_sprintf(str18, "%+10.6Le\n", val3);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%-+*.*e\n", 10, 1, 15.01);
  s21_sprintf(str18, "%-+*.*e\n", 10, 1, 15.01);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.16LE\n", val);
  s21_sprintf(str18, "%.16LE\n", val);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.0LE\n", val);
  s21_sprintf(str18, "%.0LE\n", val);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.LE\n", val1);
  s21_sprintf(str18, "%.LE\n", val1);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%.15LE\n", val2);
  s21_sprintf(str18, "%.15LE\n", val2);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%10.16LE\n", val3);
  s21_sprintf(str18, "%10.16LE\n", val3);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%+10.6LE\n", val3);
  s21_sprintf(str18, "%+10.6LE\n", val3);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%-+#*.*E\n", 10, 1, 15.01);
  s21_sprintf(str18, "%-+#*.*E\n", 10, 1, 15.01);
  ck_assert_str_eq(str17, str18);

  sprintf(str17, "%e %E\n", 0.0, 0.0);
  s21_sprintf(str18, "%e %E\n", 0.0, 0.0);
  ck_assert_str_eq(str17, str18);
  /*==================  specifier g G   ===========================*/
  char str19[100] = {'\0'};
  char str20[100] = {'\0'};

  s21_sprintf(str19, "%g", 0.50300);
  sprintf(str20, "%g", 0.50300);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%g", 0.123000);
  sprintf(str20, "%g", 0.123000);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%.5g", 0.123000);
  sprintf(str20, "%.5g", 0.123000);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%g", 0.00005);
  sprintf(str20, "%g", 0.00005);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%g", 123.456);
  sprintf(str20, "%g", 123.456);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%g", 0.0);
  sprintf(str20, "%g", 0.0);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%g", 0.00002);
  sprintf(str20, "%g", 0.00002);
  ck_assert_str_eq(str19, str20);

  s21_sprintf(str19, "%G", 0.00002);
  sprintf(str20, "%G", 0.00002);
  ck_assert_str_eq(str19, str20);

  long double num2 = 0.000005;
  s21_sprintf(str19, "%Lg", num2);
  sprintf(str20, "%Lg", num2);
  ck_assert_str_eq(str19, str20);

  END_TEST
}

Suite* s21_math_tests_create() {
  Suite* s21_string = suite_create("---string_funcs_ssprinf");
  TCase* s21_string_tests = tcase_create("ssprinf");

  suite_add_tcase(s21_string, s21_string_tests);

  tcase_add_test(s21_string_tests, sprintf_test);

  return s21_string;
}