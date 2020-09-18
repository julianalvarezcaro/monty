#include "monty.h"

/**
 * _swap - removes the top element of a stack
 *
 * @stack: stack to remove from
 * @line: current line number
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line)
{
	int elems = 0;
	stack_t *curr;

	if (*stack == NULL)
		error_handler(7, line, NULL, NULL);
	elems++;
	curr = *stack;
	while (curr->next)
	{
		elems++;
		curr = curr->next;
	}
	if (elems < 2)
		error_handler(7, line, NULL, NULL);
	elems = curr->n;
	curr->n = curr->prev->n;
	curr->prev->n = elems;
}

/**
 * _add - add the top two elements of a stack
 *
 * @stack: double pointer to the start of the stack
 * @line: current line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line)
{
	int elems = 0;
	stack_t *curr;

	if (*stack == NULL)
		m_error_handler(8, line, NULL, NULL);
	elems++;
	curr = *stack;
	while (curr->next)
	{
		elems++;
		curr = curr->next;
	}
	if (elems < 2)
		m_error_handler(8, line, NULL, NULL);
	curr->prev->n = curr->prev->n + curr->n;
	_pop(stack, line);
}

/**
 * _sub - add the top two elements of a stack
 *
 * @stack: double pointer to the start of the stack
 * @line: current line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line)
{
	int elems = 0;
	stack_t *curr;

	if (*stack == NULL)
		m_error_handler(9, line, NULL, NULL);
	elems++;
	curr = *stack;
	while (curr->next)
	{
		elems++;
		curr = curr->next;
	}
	if (elems < 2)
		m_error_handler(9, line, NULL, NULL);
	curr->prev->n = curr->prev->n - curr->n;
	_pop(stack, line);
}
