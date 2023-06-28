#include "main.h"

/**
 * get_flags - A function that calculates active flags.
 * @format: is a formatted string to print the arguments.
 * @i: an integer parameter.
 * Return: returns flags.
 */
int get_flags(const char *format, int *i)
{

int a, b;
int flags = 0;
const char F_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
const int F_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (b = *i + 1; format[b] != '\0'; b++)
{
for (a = 0; F_CHAR[a] != '\0'; a++)
if (format[b] == F_CHAR[a])
{
flags |= F_ARRAY[a];
break;
}

if (F_CHAR[a] == 0)
break;
}

*i = b - 1;

return (flags);
}
