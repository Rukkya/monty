#include "monty.h"

/**
 * exec_op - Execute a specific operation based on the given instruction.
 * @op: The operation to be executed.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void exec_op(char *op, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t valid_ops[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr,
		"L%ud: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
