#include "monty.h"

/**
 * add_node - stack header node
 * @master: head input
 * @n: value of the node
 * Return: 0 (success)
*/
void add_node(stack_t **master, int n)
{

	stack_t *nn, *stack;

	stack = *master;
	nn = malloc(sizeof(stack_t));
	if (nn == NULL)
	{ printf("Error\n");
		exit(0); }
	if (stack)
		stack->prev = nn;
	nn->n = n;
	nn->next = *master;
	nn->prev = NULL;
	*master = nn;
}
