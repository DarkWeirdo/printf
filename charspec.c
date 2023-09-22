#include"main.h"
/**
 * charspec - prints a formatted character
 * @arg_list: argument input
 * Return: returns 1 to be added to NChars
*/
int charspec(va_list arg_list)
{
char c = va_arg(arg_list, int);
_putchar(c);
return (1);
}
