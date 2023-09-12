#include "monty.h"
/**
 * push - Adds a new node to the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char **split_buff;
	int num;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free(new_node);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	split_buff = my_split(buff, " ");

	num = my_atoi(split_buff[1], line_number);

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	(*stack)->prev = new_node;
	*stack = new_node;
	free(split_buff);
}
/**
 * pop - removes the top node of the stack
 * @stack: nodes
 * @line_number: file line number
 * Return: void 
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_node = *stack;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		*stack = delete_node->next;
		(*stack)->prev = NULL;
		free(delete_node);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - swaps the top two nodes of the stack
 * @stack: nodes
 * @line_number: file line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *aux = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	aux->next = head->next;
	head->next = aux;
	(head->next)->prev = head;

	*stack = head;
}

/**
 * add - adds the top two nodes of the stack
 * @stack: nodes
 * @line_number: file line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(head->next)->n += head->n;

	pop(&head, line_number);

	*stack = head;
}
