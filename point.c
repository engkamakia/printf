#include "main.h"

/**
* print_pointer - Function that Prints the value of a pointer variable.
* @types: List of the arguments.
* @buffer: Buffer array to handle print.
* @flags:  Calculates no of active flags.
* @width: gets the width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: Number of chars printed.
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padding = ' ';
int ind = BUFF_SIZE - 2, l = 2, padding_start = 1; /* length=2, for '0x' */
unsigned long numberAdress;
char map_to[] = "0123456789abcdef";
void *address = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (address == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

numberAdress = (unsigned long)address;

while (numberAdress > 0)
{
buffer[ind--] = map_to[numberAdress % 16];
numberAdress /= 16;
l++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padding = '0';
if (flags & F_PLUS)
extra_c = '+', l++;
else if (flags & F_SPACE)
extra_c = ' ', l++;

ind++;

/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, l,
width, flags, padding, extra_c, padding_start));
}

/**
* print_non_printable - Function that Prints ascii codes in hexa.
* @types: List of the arguments.
* @buffer: Buffer array to handle print.
* @flags:  Calculates no of active flags.
* @width: gets the width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: Number of chars printed.
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int index = 0, offset = 0;
char *s = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (s == NULL)
return (write(1, "(null)", 6));

while (s[index] != '\0')
{
if (is_printable(s[index]))
buffer[index + offset] = s[index];
else
offset += append_hexa_code(s[index], buffer, index + offset);

index++;
}

buffer[index + offset] = '\0';

return (write(1, buffer, index + offset));
}

/**
* print_reverse - Function that prints reverse string.
* @types: List of the  arguments.
* @buffer: Buffer array to handle print.
* @flags:  Calculates no of active flags.
* @width: gets the width.
* @precision: specifies the precision.
* @size: specifies the size
* Return: The number of chars printed.
*/

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *s;
int index, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

s = va_arg(types, char *);

if (s == NULL)
{
UNUSED(precision);

s = ")Null(";
}
for (index = 0; s[index]; index++)
;

for (index = index - 1; index >= 0; index--)
{
char z = s[index];

write(1, &z, 1);
count++;
}
return (count);
}

/**
* print_rot13string - Function that prints a string in rot13.
* @types: List of the arguments.
* @buffer: Buffer array to handle print
* @flags:  no of active flags.
* @width: get width.
* @precision: specifies the precision.
* @size: specifies the size.
* Return: The Number of chars printed.
*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
char a;
char *s;
unsigned int i, j;
int count = 0;
char ent[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char ext[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

s = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (s == NULL)
s = "(AHYY)";
for (i = 0; s[i]; i++)
{
for (j = 0; ent[j]; j++)
{
if (ent[j] == s[i])
{
a = ext[j];
write(1, &a, 1);
count++;
break;
}
}
if (!ent[j])
{
a = s[i];
write(1, &a, 1);
count++;
}
}
return (count);
}
