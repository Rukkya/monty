#include "monty.h"

/**
 * _pall - Prints all the elements on the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file (unused).
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	(void)(line_number);

	p = *stack;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
