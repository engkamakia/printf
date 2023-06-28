#include "main.h"

/**
* print_unsigned -  Function that prints an unsigned number.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[index--] = (number % 10) + '0';
number /= 10;
}

index++;

return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_octal - Function that prints an unsigned number in octal.
* @types: List of the arguments.
* @buffer: Buffer array to handle print.
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int index = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int num = number;

UNUSED(width);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[index--] = (number % 8) + '0';
number /= 8;
}

if (flags & F_HASH && num != 0)
buffer[index--] = '0';

index++;

return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal -  Function that prints an unsigned number in hexa.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/**
* print_hexa_upper - Function that prints an unsigned number in upper hexa.
* @types: List of the arguments.
* @buffer: Buffer array to handle print.
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
* print_hexa -  Function that prints a hexadecimal number in lower or upper
* @types: List of the arguments.
* @buffer: Buffer array to handle print.
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* @flag_ch: Flag character for printing hex values.
* @map_to: maps to an array.
* Return: The Number of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int num = number;

UNUSED(width);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[index--] = map_to[number % 16];
number /= 16;
}

if (flags & F_HASH && num != 0)
{
buffer[index--] = flag_ch;
buffer[index--] = '0';
}

index++;

return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
