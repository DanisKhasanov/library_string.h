#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *buffer_str = str;
  my_sprintf flags = {0};
  va_list vl;
  va_start(vl, format);

  while (*format != '\0') {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flags, 0, sizeof(my_sprintf));
    }
    format = s21_flag_parser(&flags, format);
    format = s21_width_parser(&flags, format, vl);
    format = s21_accuracy_parser(&flags, format, vl);
    format = s21_length_parser(&flags, format);

    flags.specifier = *format;
    format++;

    char current_simb[500] = {'\0'};
    s21_specifiers(&flags, vl, current_simb);
    for (int i = 0; current_simb[i]; i++, str++) *str = current_simb[i];
  }

  *str = '\0';
  va_end(vl);
  return str - buffer_str;
}

const char *s21_flag_parser(my_sprintf *flags, const char *format) {
  const char *flags_simbol = "-+ 0#";
  while (s21_strchr(flags_simbol, *format) != NULL) {
    switch (*format) {
      case '-':
        flags->minus = 1;
        break;
      case '+':
        flags->plus = 1;
        break;
      case ' ':
        flags->space = 1;
        break;
      case '#':
        flags->lattice = 1;
        break;
      case '0':
        flags->zero = 1;
        break;
    }
    format++;
  }
  return format;
}
const char *s21_width_parser(my_sprintf *flags, const char *format,
                             va_list vl) {
  int width = 0;
  if (*format >= '0' && *format <= '9') {
    while (*format >= '0' && *format <= '9') {
      width = width * 10 + (*format - '0');
      format++;
    }
    flags->width = width;
  }
  if (*format == '*') {
    flags->width = va_arg(vl, int);
    format++;
  }

  return format;
}
const char *s21_accuracy_parser(my_sprintf *flags, const char *format,
                                va_list vl) {
  int accuracy = 0;

  if (*format == '.') {
    flags->acceracy_dot = 1;
    format++;
  }

  if (*format >= '0' && *format <= '9') {
    while (*format >= '0' && *format <= '9') {
      accuracy = accuracy * 10 + (*format - '0');
      format++;
    }
    flags->accuracy = accuracy;
  }

  if (*format == '*') {
    flags->accuracy = va_arg(vl, int);
    format++;
  }

  return format;
}
const char *s21_length_parser(my_sprintf *flags, const char *format) {
  const char *length_simbol = "hlL";

  while (s21_strchr(length_simbol, *format) != NULL) {
    switch (*format) {
      case 'h':
        flags->h = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'L':
        flags->L = 1;
        break;
    }
    format++;
  }
  return format;
}

void s21_specifiers(my_sprintf *flags, va_list vl, char *current_simb) {
  if (flags->specifier == 'c')
    s21_specifier_c(flags, vl, current_simb);
  else if (flags->specifier == 'd')
    s21_specifier_d(flags, vl, current_simb);
  else if (flags->specifier == 'f')
    s21_specifier_f(flags, vl, current_simb);
  else if (flags->specifier == 's')
    s21_specifier_s(flags, vl, current_simb);
  else if (flags->specifier == 'o' || flags->specifier == 'u' ||
           flags->specifier == 'x' || flags->specifier == 'X')
    s21_specifier_ouxX(flags, vl, current_simb);
  else if (flags->specifier == '%')
    current_simb[0] = '%';
  else if (flags->specifier == 'g' || flags->specifier == 'G')
    s21_specifier_gG(flags, vl, current_simb);
  else if (flags->specifier == 'e' || flags->specifier == 'E')
    s21_specifier_eE(flags, vl, current_simb);
  else if (flags->specifier == 'p')
    s21_specifier_p(flags, vl, current_simb);
}

void s21_specifier_c(my_sprintf *flags, va_list vl, char *current_simb) {
  char sim_format = va_arg(vl, int);
  if (flags->width && !flags->minus) {
    for (int i = 0; i < flags->width; i++) {
      current_simb[i] = ' ';
      if (i == flags->width - 1) current_simb[i] = sim_format;
    }
  } else if (flags->width) {
    current_simb[0] = sim_format;
    for (int i = 1; i < flags->width; i++) {
      current_simb[i] = ' ';
    }
  } else {
    current_simb[0] = sim_format;
  }
}
void s21_specifier_d(my_sprintf *flags, va_list vl, char *current_simb) {
  int64_t num = va_arg(vl, int64_t);
  char buff[500] = {'\0'};
  int index_buff = 498;

  if (flags->l) {
    num = (int64_t)num;
  } else if (flags->h) {
    num = (int16_t)num;
  } else {
    num = (int32_t)num;
  }

  int check_minus = num < 0 ? 1 : 0;
  num = check_minus ? -num : num;

  if (num == 0) buff[index_buff + 1] = '0';

  for (; num > 0; num /= 10, index_buff--) {
    buff[index_buff] = "0123456789"[num % 10];
  }

  for (int i = 0; buff[index_buff + 1]; index_buff++, i++) {
    if (check_minus && i == 0) current_simb[i++] = '-';
    current_simb[i] = buff[index_buff + 1];
  }
  s21_accuracy_spec(flags, current_simb);
  s21_width_and_flags_spec(flags, current_simb);
}
void s21_specifier_f(my_sprintf *flags, va_list vl, char *current_simb) {
  long double num = 0;

  if (!flags->acceracy_dot) flags->accuracy = 6;

  if (flags->L) {
    num = va_arg(vl, long double);
  } else {
    num = va_arg(vl, double);
  }

  s21_double_in_str(num, flags, current_simb);
  s21_width_and_flags_spec(flags, current_simb);
}
void s21_specifier_s(my_sprintf *flags, va_list vl, char *current_simb) {
  char *srt_format = va_arg(vl, char *);
  char str[500] = {'\0'};
  s21_strcpy(str, srt_format);

  if (flags->acceracy_dot) str[flags->accuracy] = '\0';

  int length_str = s21_strlen(str);
  int width_str = flags->width - length_str;

  if (flags->minus && width_str > 0) {
    s21_strcpy(current_simb, str);
    s21_memset(current_simb + length_str, ' ', width_str);
  } else if (width_str > 0) {
    s21_memset(current_simb, ' ', width_str);
    s21_strcpy(current_simb + width_str, str);
  } else {
    s21_strcpy(current_simb, str);
  }
}
void s21_specifier_gG(my_sprintf *flags, va_list vl, char *current_simb) {
  long double num = 0;
  char sign_degree = '-';

  if (flags->L)
    num = va_arg(vl, long double);
  else
    num = va_arg(vl, double);

  if (!flags->acceracy_dot) flags->accuracy = 6;
  if (!flags->accuracy == 0) flags->accuracy = 1;

  long double copy_num = num;
  int degree = 0;
  if ((int)num - num) {
    while ((int)copy_num == 0) {
      degree++;
      copy_num *= 10;
    }
  }

  if (degree > 4) {
    flags->accuracy = 0;
    s21_double_in_str(copy_num, flags, current_simb);
  } else {
    flags->accuracy = 10;
    s21_double_in_str(num, flags, current_simb);
  }

  if (degree > 4) {
    s21_exhibitor_in_str(degree, sign_degree, current_simb, flags);
  }

  s21_work_zero(current_simb);
  s21_width_and_flags_spec(flags, current_simb);
}

void s21_specifier_eE(my_sprintf *flags, va_list vl, char *current_simb) {
  long double num = 0;
  int degree = 0;

  if (flags->L)
    num = va_arg(vl, long double);
  else
    num = va_arg(vl, double);

  if (!flags->acceracy_dot) flags->accuracy = 6;

  char sign_degree = (int)num == 0 ? '-' : '+';

  if ((int)num - num) {
    while ((int)num == 0) {
      degree++;
      num *= 10;
    }
  } else {
    sign_degree = '+';
  }

  while ((int)num / 10 != 0) {
    degree++;
    num /= 10;
  }

  s21_double_in_str(num, flags, current_simb);
  s21_exhibitor_in_str(degree, sign_degree, current_simb, flags);
  s21_width_and_flags_spec(flags, current_simb);
}
void s21_specifier_ouxX(my_sprintf *flags, va_list vl, char *current_simb) {
  int64_t num = va_arg(vl, int64_t);

  if (flags->l) {
    num = (int64_t)num;
  } else if (flags->h) {
    num = (int16_t)num;
  } else {
    num = (int32_t)num;
  }

  if (flags->specifier == 'o') {
    s21_unsigned_in_str(flags, num, current_simb, 8);
  } else if (flags->specifier == 'u') {
    s21_unsigned_in_str(flags, num, current_simb, 10);
  } else if (flags->specifier == 'x' || flags->specifier == 'X') {
    s21_unsigned_in_str(flags, num, current_simb, 16);
  }
  s21_accuracy_spec(flags, current_simb);
  s21_width_and_flags_spec(flags, current_simb);
}
void s21_specifier_p(my_sprintf *flags, va_list vl, char *current_simb) {
  s21_unsigned_in_str(flags, va_arg(vl, int64_t), current_simb, 16);
  s21_accuracy_spec(flags, current_simb);
  s21_width_and_flags_spec(flags, current_simb);
}

void s21_accuracy_spec(my_sprintf *flags, char *current_simb) {
  char buffer_accuracy[500] = {'\0'};
  int check_minus = 0;
  int length = s21_strlen(current_simb);

  if (current_simb[0] == '-') {
    buffer_accuracy[0] = '-';
    length--;
    check_minus = 1;
  }

  if (flags->accuracy > length) {
    int i = 0;
    for (i = check_minus; i < flags->accuracy - length + check_minus; i++)
      buffer_accuracy[i] = '0';
    for (int b = check_minus; current_simb[b]; b++, i++)
      buffer_accuracy[i] = current_simb[b];
    s21_strcpy(current_simb, buffer_accuracy);
  }
}
void s21_width_and_flags_spec(my_sprintf *flags, char *current_simb) {
  char buffer_width[500] = {'\0'};
  if (flags->plus && flags->specifier != 'u') {
    buffer_width[0] = current_simb[0] == '-' ? current_simb[0] : '+';
    s21_strcpy(buffer_width + 1,
               current_simb[0] == '-' ? current_simb + 1 : current_simb);
    s21_strcpy(current_simb, buffer_width);
  } else if (flags->space && current_simb[0] != '-' &&
             flags->specifier != 'u') {
    buffer_width[0] = ' ';
    s21_strcpy(buffer_width + 1, current_simb);
    s21_strcpy(current_simb, buffer_width);
  }
  if (flags->width > (int)s21_strlen(current_simb)) {
    int index = flags->width - s21_strlen(current_simb);
    if (!flags->minus) {
      s21_memset(buffer_width, flags->zero ? '0' : ' ', index);
      s21_strcpy(buffer_width + index, current_simb);
    } else {
      s21_strcpy(buffer_width, current_simb);
      s21_memset(buffer_width + s21_strlen(buffer_width), ' ', index);
    }
    s21_strcpy(current_simb, buffer_width);
  }
}
void s21_double_in_str(long double num, my_sprintf *flags, char *current_simb) {
  char buffer_double[500] = {'\0'};
  int index_buff = 498;
  int check_minus = num < 0 ? 1 : 0;
  num = check_minus ? -num : num;
  long double befor_dot = 0;
  long double after_dot = modfl(num, &befor_dot);
  if (flags->accuracy == 0) {
    befor_dot = round(num);
    after_dot = 0;
  }
  char transl_str[500] = {'\0'};
  for (int i = 0; i < flags->accuracy; i++) {
    after_dot *= 10;
    transl_str[i] = (int)after_dot + '0';
  }
  long long right = roundl(after_dot);
  long long left = befor_dot;
  if (right == 0) {
    for (int i = 0; i < flags->accuracy; index_buff--, i++)
      buffer_double[index_buff] = '0';
  } else {
    for (int i = s21_strlen(transl_str); right || i > 0;
         right /= 10, index_buff--, i--)
      buffer_double[index_buff] = (int)(right % 10 + 0.05) + '0';
  }
  if ((flags->acceracy_dot && flags->accuracy != 0) || (int)after_dot != 0 ||
      (!flags->acceracy_dot && num == 0) || s21_strlen(transl_str) != 0)
    buffer_double[index_buff--] = '.';
  if (left == 0) {
    buffer_double[index_buff] = '0';
    index_buff--;
  } else {
    for (; left; left /= 10, index_buff--)
      buffer_double[index_buff] = (int)(left % 10) + '0';
  }
  for (int i = 0; buffer_double[index_buff + 1]; index_buff++, i++) {
    if (check_minus && i == 0) {
      current_simb[i] = '-';
      i++;
    }
    current_simb[i] = buffer_double[index_buff + 1];
  }
}
void s21_unsigned_in_str(my_sprintf *flags, int64_t num, char *current_simb,
                         int size_num) {
  char buff_unsigner[500] = {'\0'};
  int index_buff = 498;

  if (num == 0) buff_unsigner[index_buff + 1] = '0';

  for (; num > 0; num /= size_num, index_buff--) {
    if (flags->specifier == 'X') {
      buff_unsigner[index_buff] = "0123456789ABCDEF"[num % size_num];
    } else {
      buff_unsigner[index_buff] = "0123456789abcdef"[num % size_num];
    }
  }

  for (int i = 0; buff_unsigner[index_buff + 1]; index_buff++, i++) {
    current_simb[i] = buff_unsigner[index_buff + 1];
  }

  if (flags->lattice && flags->specifier == 'o' && current_simb != 0) {
    s21_memmove(current_simb + 1, current_simb, s21_strlen(current_simb));
    current_simb[0] = '0';
  } else if (flags->lattice && flags->specifier == 'X' && current_simb != 0) {
    s21_memmove(current_simb + 2, current_simb, s21_strlen(current_simb));
    current_simb[0] = '0';
    current_simb[1] = 'X';
  } else if ((flags->lattice && flags->specifier == 'x' && current_simb != 0) ||
             flags->specifier == 'p') {
    s21_memmove(current_simb + 2, current_simb, s21_strlen(current_simb));
    current_simb[0] = '0';
    current_simb[1] = 'x';
  }
}
void s21_exhibitor_in_str(int degree, char sign_degree, char *current_simb,
                          my_sprintf *flags) {
  int length_str = s21_strlen(current_simb);
  char simb_degree =
      (flags->specifier == 'E' || flags->specifier == 'G') ? 'E' : 'e';

  current_simb[length_str] = simb_degree;
  current_simb[length_str + 1] = sign_degree;
  current_simb[length_str + 2] = (degree / 10) % 10 + '0';
  current_simb[length_str + 3] = degree % 10 + '0';
  current_simb[length_str + 4] = '\0';
}

void s21_work_zero(char *current_simb) {
  int length_str = s21_strlen(current_simb);
  char *dot = s21_strchr(current_simb, '.');
  if (dot) {
    for (int i = length_str - 1; current_simb[i] != '.'; i--) {
      if (current_simb[i] == '0')
        current_simb[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0') dot[0] = '\0';
  }
}