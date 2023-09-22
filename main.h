#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind,
va_list list, char buf[], int fl, int wi, int pre, int s);

void print_buf(char buf[], int *buff_ind);

int print_char(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_string(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_percent(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int print_int(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_binary(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_unsigned(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_octal(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_hexadecimal(va_list ty, char buf[],
int fl, int wi, int pre, int s);
int print_hexa_upper(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int print_hexa(va_list ty, char map_to[],
char buf[], int fl, char flag_ch, int wi, int pre, int s);

int print_non_printable(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int print_pointer(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int get_fl(const char *format, int *para);
int get_wi(const char *format, int *para, va_list list);
int get_pre(const char *format, int *para, va_list list);
int get_s(const char *format, int *para);

int print_reverse(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int print_rot13string(va_list ty, char buf[],
int fl, int wi, int pre, int s);

int handle_write_char(char c, char buf[],
int fl, int wi, int pre, int s);
int write_number(int is_positive, int ind, char buf[],
int fl, int wi, int pre, int s);
int write_num(int ind, char buf[], int fl, int wi, int pre,
int length, char padd, char extra_c);
int write_pointer(char buf[], int ind, int length,
int wi, int fl, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buf[],
int fl, int wi, int pre, int s);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_s_number(long int num, int s);
long int convert_s_unsgnd(unsigned long int num, int s);

#endif
