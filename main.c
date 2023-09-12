#include "monty.h"
/*
 *
 * main - Monty interpreter
 * @ac: number of arguments
 * @av: arguments
 * Return: 0 on success, other values on error
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	char **string = NULL;
	FILE *fd;
	size_t bufsize = 4069;
	int n;

	if (ac != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	string = malloc(4069 * sizeof(char *));
	
	if (string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	for (n = 0; getline(&(string[n]), &bufsize, fd) > 0; n++)
		;
						        
	fclose(fd);
	execute(string, &stack);
	free_list(string);
	return (0);
}
