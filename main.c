#include "monty.h"
int main(void)
{
	char opcode[100];
	int value;
	stack_t *stack = NULL;
	char input[100];
	unsigned int line_number = 0;

	while (1)
	{
		printf("Enter command (push, pall, exit): ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		if (sscanf(input, "%s %d", opcode, &value) == 2)
		{	
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, line_number);
			}
		}
		else if (strcmp(input, "pall\n") == 0)
		{
			pall(&stack, line_number);	
		}
		else if (strcmp(input, "exit\n") == 0)
		{
			free_stack(stack);
			break; 
		}
		else
		{
			printf("Invalid command\n");
		}
		line_number++;
	}		
	return (0);
}
