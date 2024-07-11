#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {
  int len = _printf("Hello world\n%c%s", 'c', "Hello");

  printf("\n%d\n", len);
  return (0);
}
