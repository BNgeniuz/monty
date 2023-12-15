#include "monty.h"
/**
 * mo_swap - interchangetop two elements of the stack.
 * @master: head input
 * @reader: line raed
 * Return: 0 (success)
*/
void mo_swap(stack_t **master, unsigned int reader)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	m = *master;
	stack = m->n;
	m->n = m->next->n;
	m->next->n = stack;
}
