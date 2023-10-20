#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL, *op = NULL;
	size_t n = 0;
	FILE *file;


	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, file) != -1)
	{
		line_number++;
		op = strtok(line, "\n\t\r ");
		if (op != NULL)
			exec_op(op, &stack, line_number);
	}
	exit(EXIT_SUCCESS);
}
