#include "monty.h"
/**
  * push - Pushes an element onto the stack.
  * @stack: A pointer to a pointer to the top of the stack.
  * @line_number: The line number where the push operation was encountered.
  * @value: The integer value to be pushed onto the stack.
  */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 *  * pall - Prints all the values on the stack.
 *   * @stack: A pointer to a pointer to the top of the stack.
 *    */
void pall(stack_t **stack)
{
	stack_t *current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
