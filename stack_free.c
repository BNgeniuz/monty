#include "monty.h"
/**
* free_stack - doubly frees
* @master: head input
*/
void free_stack(stack_t *master)
{
	stack_t *stack;

	stack = master;
	while (master)
	{
		stack = master->next;
		free(master);
		master = stack;
	}
}
