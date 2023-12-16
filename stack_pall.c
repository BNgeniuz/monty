#include "monty.h"

/**
 * mo_pall - prints stack pall
 * @master: head input
 * @reader: read line
 * Return: 0 (success)
*/
void mo_pall(stack_t **master, unsigned int reader)
{
	stack_t *m;
	(void)reader;

	m = *master;
	if (m == NULL)
		return;
	while (m)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
}
