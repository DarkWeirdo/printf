#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @ty: List a of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_unsigned(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(ty, unsigned long int);

num = convert_s_unsgnd(num, s);

if (num == 0)
buf[i--] = '0';

buf[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buf[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_unsgnd(0, i, buf, fl, wi, pre, s));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @ty: Lista of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_octal(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{

int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(ty, unsigned long int);
unsigned long int init_num = num;

UNUSED(wi);

num = convert_s_unsgnd(num, s);

if (num == 0)
buf[i--] = '0';

buf[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buf[i--] = (num % 8) + '0';
num /= 8;
}

if (fl & F_HASH && init_num != 0)
buf[i--] = '0';

i++;

return (write_unsgnd(0, i, buf, fl, wi, pre, s));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @ty: Lista of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_hexadecimal(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
return (print_hexa(ty, "0123456789abcdef", buf,
fl, 'x', wi, pre, s));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @ty: Lista of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_hexa_upper(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
return (print_hexa(ty, "0123456789ABCDEF", buf,
fl, 'X', wi, pre, s));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @ty: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @flag_ch: flag char
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_hexa(va_list ty, char map_to[], char buf[],
int fl, char flag_ch, int wi, int pre, int s)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(ty, unsigned long int);
unsigned long int init_num = num;

UNUSED(wi);

num = convert_s_unsgnd(num, s);

if (num == 0)
buf[i--] = '0';

buf[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buf[i--] = map_to[num % 16];
num /= 16;
}

if (fl & F_HASH && init_num != 0)
{
buf[i--] = flag_ch;
buf[i--] = '0';
}

i++;

return (write_unsgnd(0, i, buf, fl, wi, pre, s));
}
