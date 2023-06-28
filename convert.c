#include "main.h"

/**
 * handle_print - Function that prints an argument.
 * @fmt: A formatted string to print the arguments.
 * @list: A list of arguments to be printed.
 * @ind: ind.
 * @buffer: A buffer array to handle printing.
 * @flags: counts no of active flags.
 * @width: gets the  width.
 * @precision: specifies the precision.
 * @size: Size of the specifier.
 * Return: (1) or (2);
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int index, uk_length = 0, pc = -1;

fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (index = 0; fmt_types[index].fmt != '\0'; index++)
if (fmt[*ind] == fmt_types[index].fmt)
return (fmt_types[index].fn(list, buffer, flags, width, precision, size));

if (fmt_types[index].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
uk_length += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
uk_length += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
uk_length += write(1, &fmt[*ind], 1);
return (uk_length);
}
return (pc);
}

