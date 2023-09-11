#include "monty.h"
/**
  * push - Pushes an element to the stack
  * @stack: pointer to head of stack
  * @line_num: file's line number
  * Return: address of new element
  */
void push(stack_t **stack, unsigned int line_num, int value)
{
	stack_t *new_node;
	
	if (!stack)
	{
		fprintf(stderr, "L%u: stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
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

	(void)line_num;

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
