#include "monty.h"

/**
 * mo_mod - computes mod
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_mod(stack_t **master, unsigned int reader)
{
	stack_t *m;
	int length = 0, stack;

	m = *master;
	while (m)
	{
		m = m->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	m = *master;
	if (m->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	stack = m->next->n % m->n;
	m->next->n = stack;
	*master = m->next;
	free(m);
}
