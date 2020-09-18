#include "monty.h"

/**
 * _mod - add the top two elements of a stack
 *
 * @stack: double pointer to the start of the stack
 * @line: current line number
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line)
{
	int elems = 0;
	stack_t *curr;

	if (*stack == NULL)
		m_error_handler(13, line, NULL, NULL);
	elems++;
	curr = *stack;
	while (curr->next)
	{
		elems++;
		curr = curr->next;
	}
	if (elems < 2)
		m_error_handler(13, line, NULL, NULL);
	if (curr->n == 0)
		m_error_handler(11, line, NULL, NULL);
	curr->prev->n = curr->prev->n % curr->n;
	_pop(stack, line);
}
