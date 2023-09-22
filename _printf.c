#include "main.h"
/**
 * _printf - Printf main function
 * @format: format char
 * Return: No. of printed chars.
 */
int _printf(const char *format, ...)
{	int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buf[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
	if (format[i] != '%')
{	buf[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buf(buf, &buff_ind);
printed_chars++;
}
else
{	print_buf(buf, &buff_ind);
flags = get_fl(format, &i);
width = get_wi(format, &i, list);
precision = get_pre(format, &i, list);
size = get_s(format, &i);
++i;
printed = handle_print(format, &i, list, buf, flags, width,
precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buf(buf, &buff_ind);
va_end(list);
return (printed_chars);
}
