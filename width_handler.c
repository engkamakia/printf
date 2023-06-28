#include "main.h"

/**
 * get_width - A function that calculates the width for printing.
 * @format: A formatted string to print the arguments.
 * @i: A list of the arguments to be printed.
 * @list: list of arguments.
 *
 * Return: returns the width.
 */
int get_width(const char *format, int *i, va_list list)
{
int current_index;
int w = 0;

for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
{
if (is_digit(format[current_index]))
{
w *= 10;
w += format[current_index] - '0';
}
else if (format[current_index] == '*')
{
current_index++;
w = va_arg(list, int);
break;
}
else
break;
}

*i = current_index - 1;

return (w);
}
