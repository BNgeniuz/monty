#include "monty.h"

/**
* execute - opcode commands
* @aux: stack input
* @reader: line read
* @fd: monty file discriptor
* @cont: read content
* Return: 0 (success)
*/
int execute(char *cont, stack_t **aux, unsigned int reader, FILE *fd)
{
	instruction_t opst[] = {
				{"push", mo_push}, {"pall", mo_pall}, {"pint", mo_pint},
				{"pop", mo_pop},
				{"swap", mo_swap},
				{"add", mo_add},
				{"nop", mo_nop},
				{"sub", mo_sub},
				{"div", mo_div},
				{"mul", mo_mul},
				{"mod", mo_mod},
				{"pchar", mo_pchar},
				{"pstr", mo_pstr},
				{"rotl", mo_rotl},
				{"rotr", mo_rotr},
				{"queue", mo_queue},
				{"stack", mo_stack},
				{NULL, NULL}
				};
	unsigned int l = 0;
	char *pcd;

	pcd = strtok(cont, " \n\t");
	if (pcd && pcd[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[l].opcode && pcd)
	{
		if (strcmp(opcd, opst[l].opcode) == 0)
		{	opst[l].f(aux, reader);
			return (0);
		}
		l++;
	}
	if (opcd && opst[l].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", reader, opcd);
		fclose(fd);
		free(cont);
		free_stack(*aux);
		exit(EXIT_FAILURE); }
	return (1);
}
