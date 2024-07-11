#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_args(char type, va_list args);

#endif
/** MAIN_H **/
