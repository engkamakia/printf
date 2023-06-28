#include "main.h"

/**
 * get_size - function that calculates the size to cast the argument.
 * @format: this is a formatted string to print the arguments.
 * @i: A list of arguments that are to be printed.
 *
 * Return: returns the precision.
 */
int get_size(const char *format, int *i)
{
int current_index = *i + 1;
int s = 0;

if (format[current_index] == 'h')
s = S_SHORT;
else if (format[current_index] == 'l')
s = S_LONG;

if (s == 0)
*i = current_index  - 1;
else
*i = current_index;

return (s);
}
