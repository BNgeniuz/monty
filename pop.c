#include "monty.h"

/**
 * mo_pop - prints the top
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_pop(stack_t **master, unsigned int reader)
{
	stack_t *m;

	if (*master == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	m = *master;
	*master = m->next;
	free(m);
}
