#include "main.h"
/**
 * FormSpec - Decides which specifer is used
 * @spec: specifer letter after '%'
 * @arg_list: Argumet to be printed by specifer function
 * Return: returns no of chars printed
 */
int FormSpec(char spec, va_list arg_list)
{
switch (spec)
{
case 's':
return (strspec(arg_list));
break;

case '%':
return (percentspec('%'));
break;

case 'c':
return (charspec(arg_list));
break;

case 'd':
return (decispec(arg_list));
break;

case 'i':
return (intspec(arg_list));
break;

default:
return (0);
break;
}
}
