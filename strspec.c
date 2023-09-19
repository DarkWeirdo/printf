#include "main.h"
/**
 * strspec - prints string formatted input
 * @arg_list: argument input
 * Return: returns length of string to be added to NChars
*/
int strspec(va_list arg_list)
{
char *str = va_arg(arg_list, char*);
int str_len = 0;
while (str[str_len] != 0)
str_len++;
write(1, str, str_len);
return (str_len);
}
