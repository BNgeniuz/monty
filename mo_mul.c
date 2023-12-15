#include "monty.h"
/**
 * mo_mul - stack top2 multiplication
 * @master: stack input
 * @reader: counter reader
 * Return: 0 (success)
*/
void mo_mul(stack_t **master, unsigned int reader)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	m = *master;
	stack = m->next->n * m->n;
	m->next->n = stack;
	*master = m->next;
	free(m);
}
