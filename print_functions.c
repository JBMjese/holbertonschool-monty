#include "monty.h"
/**
  * print_all - Prints all elements in the stack
  * @stack: Pointer to the stack
  * @line_number: Line number of the instruction in the Monty file
  */
void print_all(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
/**
  * print_top - Prints the top element of the stack
  * @stack: Pointer to the stack
  * @line_number: Line number of the instruction in the Monty file
  */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
/**
  * no_operation - Performs no operation
  * @stack: Pointer to the stack
  * @line_number: Line number of the instruction in the Monty file
  */
void no_operation(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
