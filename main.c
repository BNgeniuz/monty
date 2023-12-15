#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *fd;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *aux = NULL;
	unsigned int reader = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	bus.file = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		cont = NULL;
		read_line = getline(&cont, &size, fd);
		bus.content = cont;
		reader++;
		if (read_line > 0)
		{
			execute(cont, &aux, reader, fd);
		}
		free(cont);
	}
	free_stack(aux);
	fclose(fd);
return (0);
}
