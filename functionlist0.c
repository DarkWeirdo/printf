#include "main.h"
/**
 * print_char - Prints  char
 * @ty: List of arguments
 * @buf: buf array to handle print
 * @fl:  determine flags
 * @wi: determine width
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_char(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
char c = va_arg(ty, int);

return (handle_write_char(c, buf, fl, wi, pre, s));
}
/**
 * print_string - Prints string
 * @ty: List of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_string(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
int length = 0, i;
char *str = va_arg(ty, char *);

UNUSED(buf);
UNUSED(fl);
UNUSED(wi);
UNUSED(pre);
UNUSED(s);
if (str == NULL)
{
str = "(null)";
if (pre >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (pre >= 0 && pre < length)
length = pre;

if (wi > length)
{
if (fl & F_MINUS)
{
write(1, &str[0], length);
for (i = wi - length; i > 0; i--)
write(1, " ", 1);
return (wi);
}
else
{
for (i = wi - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (wi);
}
}

return (write(1, str, length));
}
/**
 * print_percent - Prints a % sign
 * @ty: List of arguments
 * @buf: buf array to for print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_percent(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
UNUSED(ty);
UNUSED(buf);
UNUSED(fl);
UNUSED(wi);
UNUSED(pre);
UNUSED(s);
return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @ty: Lista of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_int(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(ty, long int);
unsigned long int num;

n = convert_s_number(n, s);

if (n == 0)
buf[i--] = '0';

buf[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buf[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_negative, i, buf, fl, wi, pre, s));
}
/**
 * print_binary - Prints an unsigned number
 * @ty: Lista of arguments
 * @buf: buf array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_binary(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;

UNUSED(buf);
UNUSED(fl);
UNUSED(wi);
UNUSED(pre);
UNUSED(s);

n = va_arg(ty, unsigned int);
m = 2147483648;
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
count++;
}
}
return (count);
}
