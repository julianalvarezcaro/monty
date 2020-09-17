#include "monty.h"

/**
* freeStack - frees the space allocate for a stack
*
* @stack: strack to be free'd
*
* Return: void
*/
void freeStack(stack_t *stack)
{
	if (stack == NULL)
		return;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}