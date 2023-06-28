#include "main.h"

/**
 * handle_write_char - function that prints a string.
 * @c: char types.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @width: gets the width.
 * @precision: specifies the precision.
 * @size: specifies the size.
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is positioned to the  left and padding to the buffer's right */
int index = 0;
char padding = ' ';

UNUSED(precision);
UNUSED(size);

if (flags & F_ZERO)
padding = '0';

buffer[index++] = c;
buffer[index] = '\0';

if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (index = 0; index < width - 1; index++)
buffer[BUFF_SIZE - index - 2] = padding;

if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
write(1, &buffer[0], 1));
}

return (write(1, &buffer[0], 1));
}

/**
 * write_number - function that prints a string.
 * @is_negative: A list of arguments.
 * @ind: char types.
 * @buffer: An array to handle printing.
 * @flags:  number of active flags.
 * @width: gets the width.
 * @precision: specifies the precion.
 * @size: specifies the size.
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int l = BUFF_SIZE - ind - 1;
char padding = ' ', extra_ch = 0;

UNUSED(size);

if ((flags & F_ZERO) && !(flags & F_MINUS))
padding = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';

return (write_num(ind, buffer, flags, width, precision,
l, padding, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: specifies the precision
 * @length: length
 * @padd: Padfing char.
 * @extra_c: An extra char.
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int index, padding_s = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0); /* printf(".0d", 0)  no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; /* the width is displayed with padding ' ' */
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (index = 1; index < width - length + 1; index++)
buffer[index] = padd;
buffer[index] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of the padd */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], index - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')/* add char to left of the padd */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], index - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* add char to left of the padd */
{
if (extra_c)
buffer[--padding_s] = extra_c;
return (write(1, &buffer[padding_s], index - padding_s) +
write(1, &buffer[ind], length - (1 - padding_s)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Function that writes an unsigned number.
 * @is_negative: A number indicating if the number is negative.
 * @ind: The index at which the number starts.
 * @buffer: Array of chars.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: specifies the precision.
 * @size: specifies the size.
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)
{
/* number is stored at the buffer's right and starts at position index */
int l = BUFF_SIZE - ind - 1, index = 0;
char padding = ' ';

UNUSED(is_negative);
UNUSED(size);

if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0); /* printf(".0d", 0)  no char is printed */

if (precision > 0 && precision < l)
padding = ' ';

while (precision > l)
{
buffer[--ind] = '0';
l++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padding = '0';

if (width > l)
{
for (index = 0; index < width - l; index++)
buffer[index] = padding;

buffer[index] = '\0';

if (flags & F_MINUS) /* Asign an extra char to left of the padd */
{
return (write(1, &buffer[ind], l) + write(1, &buffer[0], index));
}
else /* Asign an extra char to left of the padd */
{
return (write(1, &buffer[0], index) + write(1, &buffer[ind], l));
}
}

return (write(1, &buffer[ind], l));
}

/**
 * write_pointer - Function that writes a memory address.
 * @buffer: An arrays of chars.
 * @ind: Index at which the number starts in the buffer.
 * @length: Length.
 * @width: specifies the width.
 * @flags: Flags specifier.
 * @padd: represents the padding.
 * @extra_c: represents extra char.
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int index;

if (width > length)
{
for (index = 3; index < width - length + 3; index++)
buffer[index] = padd;
buffer[index] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of the padd */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], index - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')/* add char to left of the padd */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], index - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* add char to left of the padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], index - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
