#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string - may contain specifiers.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int i, ret = 0;
	char ch;

	if (format == NULL)
		return (-1);

	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (convert(format + i + 1) != NULL)
			{
				i++;
				ret += convert(format + i)(args, output);
				continue;
			}
			if (*(format + i + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}

		ch = *(format + i);
		ret += _memcpy(output, &ch, 1);
	}

	write(1, output->start, output->len);
	va_end(args);
	free_buffer(output);

	return (ret);
}
