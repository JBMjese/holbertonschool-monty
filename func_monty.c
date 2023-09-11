#include "monty.h"
/**
  * push - Pushes an element to the stack
  * @stack: pointer to head of stack
  * @line_num: file's line number
  * Return: address of new element
  */
void push(stack_t **stack, unsigned int line_number)
{
	char **split_buff;
	int num;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free(new);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	split_buff = _split(buff, " ");

	num = _atoi(split_buff[1], line_number);

	new->n = num;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	free(split_buff);
}
/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void)line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
  * free_stack - Frees all the nodes in a stack.
  * @stack: Pointer to the head of the stack.
  * Description: This function frees all the nodes in the stack and the stack
  * itself. It should be called when the program is about to exit to avoid
  * memory leaks.
  */
void free_stack(stack_t *stack)
{
	stack_t *current;

	if (!stack)
	return;
	
	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
  * _atoi - function converts a string to integer
  * @str: string to convert
  * @line_number: file line number
  * Return: int
  */

int _atoi(char *str, unsigned int line_number)
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
/**
  * _calloc - function that allocates memory for an array, using malloc
  * @nmemb: array
  * @size: size
  * Return: pointer or NULL
  */

void *_calloc(unsigned int nmemb, unsigned int size)
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
