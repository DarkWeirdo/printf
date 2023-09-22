#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @ty: List a of arguments
 * @buf: Buffer array to handle print
 * @fl:  determine flag
 * @wi: determine width.
 * @pre: precision spec
 * @s: size spec
 * Return: Number of printed chars
 */
int print_pointer(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(ty, void *);

UNUSED(wi);
UNUSED(s);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buf[BUFF_SIZE - 1] = '\0';
UNUSED(pre);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buf[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}

if ((fl & F_ZERO) && !(fl & F_MINUS))
padd = '0';
if (fl & F_PLUS)
extra_c = '+', length++;
else if (fl & F_SPACE)
extra_c = ' ', length++;

ind++;

return (write_pointer(buf, ind, length,
wi, fl, padd, extra_c, padd_start));
}

/**
* print_non_printable - Prints ascii codes in hexa of non printable chars
* @ty: Lista of arguments
* @buf: Buffer array to handle print
* @fl:  determine flag
* @wi: determine width.
* @pre: precision spec
* @s: size spec
* Return: Number of printed chars
*/
int print_non_printable(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
int i = 0, offset = 0;
char *str = va_arg(ty, char *);

UNUSED(fl);
UNUSED(wi);
UNUSED(pre);
UNUSED(s);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (is_printable(str[i]))
buf[i + offset] = str[i];
else
offset += append_hexa_code(str[i], buf, i + offset);

i++;
}

buf[i + offset] = '\0';

return (write(1, buf, i + offset));
}

/**
* print_reverse - Prints reverse string.
* @ty: Lista of arguments
* @buf: Buffer array to handle print
* @fl:  determine flag
* @wi: determine width.
* @pre: precision spec
* @s: size spec
* Return: Number of printed chars
*/

int print_reverse(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
char *str;
int i, count = 0;

UNUSED(buf);
UNUSED(fl);
UNUSED(wi);
UNUSED(s);

str = va_arg(ty, char *);

if (str == NULL)
{
UNUSED(pre);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}
/**
* print_rot13string - Print a string in rot13.
* @ty: Lista of arguments
* @buf: Buffer array to handle print
* @fl:  determine flag
* @wi: determine width.
* @pre: precision spec
* @s: size spec
* Return: Number of printed chars
*/
int print_rot13string(va_list ty, char buf[],
int fl, int wi, int pre, int s)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(ty, char *);
UNUSED(buf);
UNUSED(fl);
UNUSED(wi);
UNUSED(pre);
UNUSED(s);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
