#include "main.h"

/**
 * free_buffer - Frees a buffer_t struct.
 * @output: The buffer_t struct to be freed.
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}
