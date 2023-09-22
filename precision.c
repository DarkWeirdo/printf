#include "main.h"

/**
 * get_pre - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @para: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_pre(const char *format, int *para, va_list list)
{
int curr_para = *para + 1;
int precision = -1;

if (format[curr_para] != '.')
return (precision);

precision = 0;

for (curr_para += 1; format[curr_para] != '\0'; curr_para++)
{
if (is_digit(format[curr_para]))
{
precision *= 10;
precision += format[curr_para] - '0';
}
else if (format[curr_para] == '*')
{
curr_para++;
precision = va_arg(list, int);
break;
}
else
break;
}

*para = curr_para - 1;

return (precision);
}
