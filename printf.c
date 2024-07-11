#include "main.h"

/**
 * _printf: print ARGUEMENT(s) according to FORMAT
 * @format:  a string that specifies the format of the arguements to be printed
 * @...: an array of arguements
 */
int _printf(const char *format, ...) {
  int len = 0;
  int i;
  char c, type;
  va_list args;
  va_start(args, format);

  for (i = 0; format[i]; i++) {
    c = format[i];
    if (c != '%') {
      _putchar(c);
      len++;
      continue;
    }

    i++;
    type = format[i];
    len += print_args(type, args);
  }

  return len;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c) { return (write(STDOUT_FILENO, &c, 1)); }

/**
 * print_args - prints an arg based on type
 * @type: specifies type of arg to print
 * @args: list of args to print
 */
int print_args(char type, va_list args) {
  void *value;
  char *str;
  int j;
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
    for (j = 0; str[j]; j++) {
      _putchar(str[j]);
      len++;
    }
    break;
  }
  return len;
}
