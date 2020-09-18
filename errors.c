#include "monty.h"

/**
 * error_handler - prints error message and exit with exit code
 *
 * @error_code: indicates what error procedure to follow
 * @line: line number where the error ocurred
 * @opcode: function tryied to be executed
 * @pathname: file that is trying to be open
 *
 * Return: void
 */
void error_handler(int error_code, int line, char *opcode, char *pathname)
{
	switch (error_code)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", pathname);
			exit(EXIT_FAILURE);
			break;
		case 2:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
			break;
		case 3:
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		case 5:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			exit(EXIT_FAILURE);
		case 6:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			exit(EXIT_FAILURE);
		case 7:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			exit(EXIT_FAILURE);
	}
}

/**
 * m_error_handler - prints error message and exit with exit code
 *
 * @error_code: indicates what error procedure to follow
 * @line: line number where the error ocurred
 * @opcode: function tryied to be executed
 * @pathname: file that is trying to be open
 *
 * Return: void
 */
void m_error_handler(int error_code, int line, char *opcode, char *pathname)
{
	(void) opcode;
	(void) pathname;

	switch (error_code)
	{
		case 8:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			exit(EXIT_FAILURE);
		case 9:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			exit(EXIT_FAILURE);
		case 10:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			exit(EXIT_FAILURE);
		case 11:
			fprintf(stderr, "L%d: division by zero\n", line);
			exit(EXIT_FAILURE);
	}
}
