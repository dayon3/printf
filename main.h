#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	char specifier;
	int (*func)(va_list, buffer_t *);
} converter_t;

int _printf(const char *format, ...);

/* Conversion Functions */
int convert_c(va_list args, buffer_t *output);
int convert_s(va_list args, buffer_t *output);
int convert_di(va_list args, buffer_t *output);
int convert_percent(va_list args, buffer_t *output);

/* Helper Functions */
void init_buffer(buffer_t *output);
int (*convert(const char *specifier))(va_list, buffer_t *);
int _memcpy(buffer_t *output, char *src, unsigned int n);
int convert_sbase(buffer_t *output, int num, char *base);
int convert_ubase(buffer_t *output, unsigned long int num, char *base);

#endif
