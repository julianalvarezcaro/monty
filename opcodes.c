#include "monty.h"

/**
 * _push - pushes an elemento to the stack
 *
 * @stack: stack to push to
 * @line: current line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line)
{

	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(3, line, NULL, NULL);

	/*Valores fijos, independiente de la sitaucion*/
	new->n = argument;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
		return;
	}
	new->prev = *stack;
	while (new->prev->next)
	{
		new->prev = new->prev->next;
	}

	new->prev->next = new;
}

/**
 * _pall - prints element of a stack from the top
 *
 * @stack: stack to be printed
 * @line: current line number
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *curr;
	(void) line;

	if (*stack == NULL)
		return;

	curr = *stack;
	while (curr->next)
		curr = curr->next;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * _pint - prints the top element of a stack
 *
 * @stack: stack to print element from
 * @line: current line number
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	if (*stack == NULL)
		error_handler(5, line, NULL, NULL);
	curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	printf("%d\n", curr->n);
}

/**
 * _pop - removes the top element of a stack
 *
 * @stack: stack to remove from
 * @line: current line number
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	if (*stack == NULL)
		error_handler(6, line, NULL, NULL);
	curr = *stack;
	while (curr->next)
	{
		curr = curr->next;
	}
	if (curr->prev == NULL)
		*stack = NULL;
	else
		curr->prev->next = NULL;
	free(curr);
}

/**
 * _empty - does nothing
 *
 * @stack: pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void _empty(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
}
