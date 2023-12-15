#include "monty.h"

/**
 * mo_queue - prints the top
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_queue(stack_t **master, unsigned int reader)
{
	(void)master;
	(void)reader;
	bus.lifi = 1;
}

/**
 * add_queue - add tail stack
 * @o: input value
 * @master: head input
 * Return: 0 (success)
*/
void add_queue(stack_t **master, int o)
{
	stack_t *nn, *stack;

	stack = *master;
	nn = malloc(sizeof(stack_t));
	if (nn == NULL)
	{
		printf("Error\n");
	}
	nn->n = o;
	nn->next = NULL;
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	if (!stack)
	{
		*master = nn;
		nn->prev = NULL;
	}
	else
	{
		stack->next = nn;
		nn->prev = stack;
	}
}
