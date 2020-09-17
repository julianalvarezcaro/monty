#include "monty.h"

/**
 * openfile - opens and reads a file to be interpreted
 *
 * @pathname: path of the file to be opened
 * @stack: stack to perform the opcode with/to
 *
 * Return: void
 */
FILE *openfile(char *pathname, stack_t **stack)
{
	FILE *fd;
	size_t len = 0;
	ssize_t read;
	char *text = NULL, *cptext, *opcode, *arg;
	int line = 0;
	void (*func)(stack_t **, unsigned int);

	/*Open the file and validate if worked*/
	fd = fopen(pathname, "r");
	if (fd == NULL)
		error_handler(1, line, NULL, pathname);

	/*We read one line and stores it in text*/
	while ((read = getline(&text, &len, fd)) != -1)
	{
		line++;
		cptext = strdup(text);
		_split(cptext, &opcode, &arg);
		func = get_func(opcode);
		if (func == NULL)
			error_handler(2, line, opcode, NULL);
		if (func == _push)
			validArg(arg, line);
		func(stack, line);
		free(cptext);
	}
	/*Confirming it is free'd*/
	if (text)
		free(text);
	return (fd);
}
