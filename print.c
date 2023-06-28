#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function equivalent to printf.
 * @format: format.
 * Return: returns the Printed characters.
 */
int _printf(const char *format, ...)
{
int i, j = 0, k = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
k++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
j = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (j == -1)
return (-1);
k += j;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (k);
}

/**
 * print_buffer - function that Prints the contents of the buffer if it exist.
 * @buffer: refers to the Array of chars.
 * @buff_ind: Index at which to add next character.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
