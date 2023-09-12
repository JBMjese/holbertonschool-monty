#include "monty.h"
/**
  * check_opcodes - Checks for a valid opcode in the input line
  * Return: A pointer to the function, or NULL if not found
  */
void (*check_opcodes(void))(stack_t **, unsigned int)
{
	int i = 0, j;
	int valid_opcode;
	int opcode_length;

	instruction_t opcodes[] = {
	{"push", push},
	{"pall", print_all},
	{"pint", print_top},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", no_operation},
	{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		j = 0;
		valid_opcode = 1;
		opcode_length = strlen(opcodes[i].opcode);
		while (j < opcode_length)
		{
			if (opcodes[i].opcode[j] != buff[j])
			{
				valid_opcode = 0;
				break;
			}
			j++;
		}
		if (valid_opcode == 1 && (buff[j] == '\n'
			|| buff[j] == ' ' || buff[j] == '\0'))
			break;
		i++;
	}
	return (opcodes[i].f);
}
