#include "monty.h"
int main(void)
{
	char opcode[100];
	int value;
	stack_t *stack = NULL;
	char input[100];

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
				push(&stack, value);
			}
			free(opcode);
		}
		else if (strcmp(input, "pall\n") == 0)
		{
			pall(&stack);	
		}
		else if (strcmp(opcode, "exit\n") == 0)
		{
			break; 
		}
		else
		{
			printf("Invalid command\n");
		}
	}		
	return (0);
}
