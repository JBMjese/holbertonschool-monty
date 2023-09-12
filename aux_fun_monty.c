#include "monty.h"

/**
 * add -  Adds the top two elements of the stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *n;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		n = h->next;
		n->n += h->n;
		free(h);
		*stack = n;
	}
}
/**
 * pint -  Prints value at top of stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
  * _split - split string
  * @str: string
  * @sep: separator
  * Return: divided str
  */

char **_split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = (char **)_calloc(100, sizeof(char *));

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
