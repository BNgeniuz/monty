#include "monty.h"
/**
 * mo_pint - prints top
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_pint(stack_t **master, unsigned int reader)
{
	if (*master == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*master)->n);
}
