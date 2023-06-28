#include "main.h"

/**
 * is_printable - function to evaluate if a char is printable.
 * @c: the char to be evaluated.
 *
 * Return: (1)success or (0).
 */
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * append_hexa_code - function that appends ascci in hexa code to buffer.
 * @buffer: An array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return:returns (3)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
 * is_digit - a function that verifies if a char is a digit.
 * @c: the Char to be evaluated.
 *
 * Return: (1) success or (0) if not.
 */
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_size_number - A function that casts a number to the specified size.
 * @num: the number to be casted.
 * @size: the number indicating the type to be casted.
 *
 * Return: returns the casted value of the number.
 */
long int convert_size_number(long int num, int size)
{
if (size == S_SHORT)
return ((short)num);

else if (size == S_LONG)
return (num);
return ((int)num);
}

/**
 * convert_size_unsgnd - A function that casts a number to the specified size.
 * @num: The number to be casted by the func.
 * @size: the number indicating the type to be casted.
 *
 *
 * Return: returns the casted value of the number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_SHORT)
return ((unsigned short)num);

else if (size == S_LONG)
return (num);

return ((unsigned int)num);
}
