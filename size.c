#include "main.h"

/**
 * get_s - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @para: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_s(const char *format, int *para)
{
int curr_para = *para + 1;
int size = 0;

if (format[curr_para] == 'l')
size = S_LONG;
else if (format[curr_para] == 'h')
size = S_SHORT;

if (size == 0)
*para = curr_para - 1;
else
*para = curr_para;

return (size);
}
