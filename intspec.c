#include "main.h"
/**
 * intspec - function to handle integer format specifier
 * @arg_list: argument to process
 * Return: Returns number of processed characters
 */
int intspec(va_list arg_list)
{
int IntRefNum = va_arg(arg_list, int);
int IntTestNum, IntLDigit = IntRefNum % 10;
int IntNumDigit, e = 1;
int NChar = 1;
IntRefNum = IntRefNum / 10;
IntTestNum = IntRefNum;

if (IntLDigit < 0)
{
_putchar('-');
IntTestNum = -IntTestNum;
IntRefNum = -IntRefNum;
IntLDigit = -IntLDigit;
NChar++;
}
if (IntTestNum > 0)
{
while (IntTestNum / 10 != 0)
{
e *= 10;
IntTestNum /= 10;
}
IntTestNum = IntRefNum;
while (e > 0)
{
IntNumDigit = IntTestNum / e;
_putchar(IntNumDigit + '0');
IntTestNum -= (IntNumDigit *e);
e /= 10;
NChar++;
}
}
_putchar(IntLDigit + '0');
return (NChar);
}
