#include "monty.h"

/**
 * mo_push - push node to the stack
 * @master: head input
 * @reader: line read
 * Return: 0 (success)
*/
void mo_push(stack_t **master, unsigned int reader)
{
	int o, p = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			p++;
		for (; bus.arg[p] != '\0'; p++)
		{
			if (bus.arg[p] > 57 || bus.arg[p] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", reader);
			fclose(bus.file);
			free(bus.content);
			free_stack(*master);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", reader);
		fclose(bus.file);
		free(bus.content);
		free_stack(*master);
		exit(EXIT_FAILURE); }
	o = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(master, o);
	else
		addqueue(master, o);
}
