#include "monty.h"
/**
 * main- Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, or exit(EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_handler(argv[1]);
	return (0);
}
