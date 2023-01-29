#include "main.h"

/**
 * convert - Matches a conversion specifier with a
 *           corresponding conversion function.
 * @specifier: a pointer to a conversion specifier - character
 *
 * Return: If a conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
void (*convert(const char *specifier))(va_list, buffer_t *)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_S},
		{'%', convert_percent},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
