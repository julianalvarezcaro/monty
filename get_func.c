#include "monty.h"

/**
 * get_func -returns the propper func depending on the opcode
 *
 * @opcode: tells the function to be called
 *
 * Return: void
 */
void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"empty", _empty},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 3)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
		{
			return (inst[i].f);
		}
		i++;
	}
	return (NULL);
}
