#include "main.h"

/**
 * get_wi - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @para: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_wi(const char *format, int *para, va_list list)
{
int curr_para;
int width = 0;

for (curr_para = *para + 1; format[curr_para] != '\0'; curr_para++)
{
if (is_digit(format[curr_para]))
{
width *= 10;
width += format[curr_para] - '0';
}
else if (format[curr_para] == '*')
{
curr_para++;
width = va_arg(list, int);
break;
}
else
break;
}

*para = curr_para - 1;

return (width);
}
