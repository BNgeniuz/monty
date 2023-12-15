#include "monty.h"
/**
 * mo_add - stack add 2 top element
 * @master: input head
 * @reader: line read
 * Return: 0 (success)
*/
void mo_add(stack_t **master, unsigned int reader)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", reader);
		fclose(bus.fd);
		free(bus.cont);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	m = *master;
	stack = m->n + m->next->n;
	m->next->n = stack;
	*master = m->next;
	free(m);
}
