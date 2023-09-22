#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buf: buf array to handle print
 * @fl:  Calculates active fl.
 * @wi: get wi.
 * @pre: pre specifier
 * @s: s specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buf[],
int fl, int wi, int pre, int s)
{
int i = 0;
char padd = ' ';

UNUSED(pre);
UNUSED(s);

if (fl & F_ZERO)
padd = '0';

buf[i++] = c;
buf[i] = '\0';

if (wi > 1)
{
buf[BUFF_SIZE - 1] = '\0';
for (i = 0; i < wi - 1; i++)
buf[BUFF_SIZE - i - 2] = padd;

if (fl & F_MINUS)
return (write(1, &buf[0], 1) +
write(1, &buf[BUFF_SIZE - i - 1], wi - 1));
else
return (write(1, &buf[BUFF_SIZE - i - 1], wi - 1) +
write(1, &buf[0], 1));
}

return (write(1, &buf[0], 1));
}

/**
* write_number - Prints a string
* @is_negative: Lista of arguments
* @ind: char types.
* @buf: buf array to handle print
* @fl:  Calculates active fl
* @wi: get wi.
* @pre: pre specifier
* @s: s specifier
*
* Return: Number of chars printed.
*/
int write_number(int is_negative, int ind, char buf[],
int fl, int wi, int pre, int s)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;

UNUSED(s);

if ((fl & F_ZERO) && !(fl & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (fl & F_PLUS)
extra_ch = '+';
else if (fl & F_SPACE)
extra_ch = ' ';

return (write_num(ind, buf, fl, wi, pre,
length, padd, extra_ch));
}

/**
* write_num - Write a number using a bufffer
* @ind: Index at which the number starts on the buf
* @buf: buf
* @fl: fl
* @wi: wi
* @prec: pre specifier
* @length: Number length
* @padd: Pading char
* @extra_c: Extra char
*
* Return: Number of printed chars.
*/
int write_num(int ind, char buf[],
int fl, int wi, int prec,
int length, char padd, char extra_c)
{
int i, padd_start = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0' && wi == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
buf[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buf[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (wi > length)
{
for (i = 1; i < wi - length + 1; i++)
buf[i] = padd;
buf[i] = '\0';
if (fl & F_MINUS && padd == ' ')
{
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[ind], length) + write(1, &buf[1], i - 1));
}
else if (!(fl & F_MINUS) && padd == ' ')
{
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[1], i - 1) + write(1, &buf[ind], length));
}
else if (!(fl & F_MINUS) && padd == '0')
{
if (extra_c)
buf[--padd_start] = extra_c;
return (write(1, &buf[padd_start], i - padd_start) +
write(1, &buf[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[ind], length));
}

/**
* write_unsgnd - Writes an unsigned number
* @is_negative: Number indicating if the num is negative
* @ind: Index at which the number starts in the buf
* @buf: Array of chars
* @fl: fl specifiers
* @wi: wi specifier
* @pre: pre specifier
* @s: s specifier
*
* Return: Number of written chars.
*/
int write_unsgnd(int is_negative, int ind,
char buf[],
int fl, int wi, int pre, int s)
{
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_negative);
UNUSED(s);

if (pre == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
return (0);

if (pre > 0 && pre < length)
padd = ' ';

while (pre > length)
{
buf[--ind] = '0';
length++;
}

if ((fl & F_ZERO) && !(fl & F_MINUS))
padd = '0';

if (wi > length)
{
for (i = 0; i < wi - length; i++)
buf[i] = padd;

buf[i] = '\0';

if (fl & F_MINUS)
{
return (write(1, &buf[ind], length) + write(1, &buf[0], i));
}
else
{
return (write(1, &buf[0], i) + write(1, &buf[ind], length));
}
}

return (write(1, &buf[ind], length));
}

/**
* write_pointer - Write a memory address
* @buf: Arrays of chars
* @ind: Index at which the number starts in the buf
* @length: Length of number
* @wi: Wwi specifier
* @fl: fl specifier
* @padd: Char representing the padding
* @extra_c: Char representing extra char
* @padd_start: Index at which padding should start
*
* Return: Number of written chars.
*/
int write_pointer(char buf[], int ind, int length,
int wi, int fl, char padd, char extra_c, int padd_start)
{
int i;

if (wi > length)
{
for (i = 3; i < wi - length + 3; i++)
buf[i] = padd;
buf[i] = '\0';
if (fl & F_MINUS && padd == ' ')
{
buf[--ind] = 'x';
buf[--ind] = '0';
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[ind], length) + write(1, &buf[3], i - 3));
}
else if (!(fl & F_MINUS) && padd == ' ')
{
buf[--ind] = 'x';
buf[--ind] = '0';
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[3], i - 3) + write(1, &buf[ind], length));
}
else if (!(fl & F_MINUS) && padd == '0')
{
if (extra_c)
buf[--padd_start] = extra_c;
buf[1] = '0';
buf[2] = 'x';
return (write(1, &buf[padd_start], i - padd_start) +
write(1, &buf[ind], length - (1 - padd_start) - 2));
}
}
buf[--ind] = 'x';
buf[--ind] = '0';
if (extra_c)
buf[--ind] = extra_c;
return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}
