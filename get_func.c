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
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"sub", _sub}, {"nop", _empty},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"empty", _empty},
		{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode)
	{
		if (opcode[0] == '#')
		{
			return (_empty);
		}
		if (strcmp(opcode, inst[i].opcode) == 0)
		{
			return (inst[i].f);
		}
		i++;
	}
	return (NULL);
}
