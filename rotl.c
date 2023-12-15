#include "monty.h"

/**
 * mo_rotl- stack rotation to the top
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
 */
void mo_rotl(stack_t **master,  __attribute__((unused)) unsigned int reader)
{
	stack_t *curr = *master, *stack;

	if (*master == NULL || (*master)->next == NULL)
	{
		return;
	}
	stack = (*master)->next;
	stack->prev = NULL;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *master;
	(*master)->next = NULL;
	(*curr)->prev = curr;
	(*master) = stack;
}
