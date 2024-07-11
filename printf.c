#include "main.h"

int _printf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  int len = 0;

  for (int i = 0; format[i]; i++) {
    char c = format[i];
    if (c != '%') {
      _putchar(c);
      len++;
      continue;
    }

    i++;                   // skip the next character
    char type = format[i]; // can be c or s
    len += print_args(type, args);
  }

  return len;
}

int _putchar(char c) { return (write(STDOUT_FILENO, &c, 1)); }

int print_args(char type, va_list args) {
  void *value;
  char *str;
  int len = 0;

  switch (type) {
  case 'c':
    value = malloc(sizeof(char));
    *(char *)value = va_arg(args, int);
    _putchar(*(char *)value);
    len++;
    break;
  case 's':
    str = va_arg(args, char *);
    for (int j = 0; str[j]; j++) {
      _putchar(str[j]);
      len++;
    }
    break;
  }
  return len;
}
