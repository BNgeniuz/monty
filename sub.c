#include "monty.h"
/**
 * mo_sub- stack subs
 * @master: head input
 * reader: line read
 * Return: 0 (success)
 */
void mo_sub(stack_t **master, unsigned int reader)
{
	stack_t *stack;
	int ss, ptr;

	stack = *master;
	for (ptr = 0; stack != NULL; ptr++)
		stack = stack->next;
	if (ptr < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE);
	}
	stack = *master;
	ss = stack->next->n - stack->n;
	stack->next->n = ss;
	*master = stack->next;
	free(stack);
}
