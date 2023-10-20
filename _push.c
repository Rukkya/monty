#include "monty.h"
#include <ctype.h>

/**
 * add_snodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: The data to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL if it fails.
 */
stack_t *add_snodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	if (new->next != NULL)
		new->next->prev = new;
	new->prev = NULL;
	return (new);
}

/**
 * is_all_digit - Checks if a string is composed of digits.
 * @arg: The string to be checked.
 *
 * Return: 1 if the string is not composed of all digits, 0 otherwise.
 */
int is_all_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * _push - Pushes an element onto the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || is_all_digit(arg))
	{
		fprintf(stdout,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_snodeint(stack, n))
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
