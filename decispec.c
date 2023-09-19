#include "main.h"
/**
 * decispec - function to handle decimal format specifier
 * @arg_list: argument to process
 * Return: Returns number of processed characters
 */
int decispec(va_list arg_list)
{
int DecRefNum = va_arg(arg_list, int);
int DecTestNum, DecLDigit = DecRefNum % 10;
int DecNumDigit, e = 1;
int NChar = 1;
DecRefNum = DecRefNum / 10;
DecTestNum = DecRefNum;

if (DecLDigit < 0)
{
_putchar('-');
DecTestNum = -DecTestNum;
DecRefNum = -DecRefNum;
DecLDigit = -DecLDigit;
NChar++;
}
if (DecTestNum > 0)
{
while (DecTestNum / 10 != 0)
{
e *= 10;
DecTestNum /= 10;
}
DecTestNum = DecRefNum;
while (e > 0)
{
DecNumDigit = DecTestNum / e;
_putchar(DecNumDigit + '0');
DecTestNum -= (DecNumDigit *e);
e /= 10;
NChar++;
}
}
_putchar(DecLDigit + '0');
return (NChar);
}
