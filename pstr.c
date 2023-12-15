#include "monty.h"

/**
 * mo_pstr - stack at the top of the stack
 * @master: head input
 * @readter: line read
 * Return: 0 (success)
*/
void mo_pstr(stack_t **master, unsigned int reader)
{
	stack_t *m;
	(void)reader;

	m = *master;
	while (m)
	{
		if (m->n > 127 || m->n <= 0)
		{
			break;
		}
		printf("%c", m->n);
		m = m->next;
	}
	printf("\n");
}
