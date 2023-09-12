#include "monty.h"
/**
 * my_calloc - Allocates memory for an array using malloc
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 * Return: A pointer to the allocated memory or NULL on failure
 */
void *my_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int index = 0;
	char *ptr = NULL;

	if (nmemb == 0 || size == 0)
	return (NULL);

	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (; index < (nmemb * size); index++)
	ptr[index] = 0;
	return (ptr);
}
/**
 * my_atoi - Converts a string to an integer
 * @str: String to convert
 * @line_number: Line number in the file
 * Return: The converted integer
 */
int my_atoi(char *str, unsigned int line_number)
{
	int num = 0, i = 0;
	unsigned int valid_nums = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		valid_nums++;
		i++;
	}

	if (valid_nums != strlen(str) - 1)
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (num);
}
/**
 * my_split - Splits a string into an array of substrings
 * @str: String to split
 * @sep: Separator character
 * Return: An array of substrings
 */
char **my_split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = (char **)my_calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (aux)
	{
		split_str[i] = aux;
		aux = strtok(NULL, sep);
		i++;
	}
	return (split_str);
}

/**
 * my_free_stack - Frees a linked list
 * @head: Pointer to the head of the list
 */
void my_free_stack(stack_t *head)
{
	stack_t *stack;

	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}
