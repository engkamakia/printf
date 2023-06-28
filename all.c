#include "main.h"

/**
* print_char - Function that prints a char.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char character = va_arg(types, int);

return (handle_write_char(character, buffer, flags, width, precision, size));
}

/**
* print_string - Function that prints a string.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int l = 0, i;
char *string = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
{
string = "(null)";
if (precision >= 6)
string = "      ";
}

while (string[l] != '\0')
l++;

if (precision >= 0 && precision < l)
l = precision;

if (width > l)
{
if (flags & F_MINUS)
{
write(1, &string[0], l);
for (i = width - l; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - l; i > 0; i--)
write(1, " ", 1);
write(1, &string[0], l);
return (width);
}
}

return (write(1, string, l));
}

/**
* print_percent - Function that prints a percent sign.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}

/**
* print_int - Function that prints an int.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int index = BUFF_SIZE - 2;
int is_negative = 0;
long int long_i = va_arg(types, long int);
unsigned long int number;

long_i = convert_size_number(long_i, size);

if (long_i == 0)
buffer[index--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
number = (unsigned long int)long_i;

if (long_i < 0)
{
number = (unsigned long int)((-1) * long_i);
is_negative = 1;
}

while (number > 0)
{
buffer[index--] = (number % 10) + '0';
number /= 10;
}

index++;

return (write_number(is_negative, index, buffer, flags,
width, precision, size));
}

/**
* print_binary - Function that prints an unsigned number.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int x, y, index, sum;
unsigned int a[32];
int c;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

x = va_arg(types, unsigned int);
y = 2147483648;
a[0] = x / y;
for (index = 1; index < 32; index++)
{
y /= 2;
a[index] = (x / y) % 2;
}
for (index = 0, sum = 0, c = 0; index < 32; index++)
{
sum += a[index];
if (sum || index == 31)
{
char z = '0' + a[index];

write(1, &z, 1);
c++;
}
}
return (c);
}
