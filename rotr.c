#include "monty.h"
/**
 * mo_rotr- rotates the stack
 * @head: headd inputs
 * @reader: line read
 * Return: 0 (succes)
 */
void mo_rotr(stack_t **master, __attribute__((unused)) unsigned int reader)
{
	stack_t *cpy;

	cpy = *master;
	if (*master == NULL || (*master)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *master;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*master)->prev = cpy;
	(*master) = cpy;
}
