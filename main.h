#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int intspec(va_list arg_list);
int decispec(va_list arg_list);
int FormSpec(char spec, va_list arg_list);
int percentspec(char percent);
int charspec(va_list arg_list);
int strspec(va_list arg_list);
#endif
