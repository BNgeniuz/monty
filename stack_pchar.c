#include "monty.h"

/**
 * mo_pchar - stack top xter printing
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_pchar(stack_t **master, unsigned int reader)
{
	stack_t *m;

	m = *master;
	if (!m)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	if (m->n > 127 || m->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", m->n);
}
