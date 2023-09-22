#include "main.h"
/**
 * print_buf - Prints the contents of the buf if it exist
 * @buf: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buf(char buf[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buf[0], *buff_ind);

*buff_ind = 0;
}
