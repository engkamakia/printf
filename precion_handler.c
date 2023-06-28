#include "main.h"

/**
 * get_precision - Function to calculate the precision.
 * @format: A formatted string to print the arguments.
 * @i: A list of arguments that are to be printed.
 * @list: the list of arguments.
 *
 * Return: returns the precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int current_index = *i + 1;
int precision_index = -1;

if (format[current_index] != '.')
return (precision_index);

precision_index  = 0;

for (current_index += 1; format[current_index] != '\0'; current_index++)
{
if (is_digit(format[current_index]))
{
precision_index  *= 10;
precision_index  += format[current_index] - '0';
}
else if (format[current_index] == '*')
{
current_index++;
precision_index  = va_arg(list, int);
break;
}
else
break;
}

*i = current_index - 1;

return (precision_index);
}
