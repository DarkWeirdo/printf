#include "main.h"

/**
 * get_fl - Calculates active FL
 * @format: Formatted string in which to print the arguments
 * @para: take a parameter.
 * Return: FL:
 */
int get_fl(const char *format, int *para)
{
int j, curr_para;
int FL = 0;
const char FL_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
const int FL_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (curr_para = *para + 1; format[curr_para] != '\0'; curr_para++)
{
for (j = 0; FL_CHARS[j] != '\0'; j++)
if (format[curr_para] == FL_CHARS[j])
{
FL |= FL_ARRAY[j];
break;
}

if (FL_CHARS[j] == 0)
break;
}

*para = curr_para - 1;

return (FL);
}
