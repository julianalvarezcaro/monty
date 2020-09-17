#include "monty.h"

/**
 * main - Will open the file to start reading it
 *
 * @argc: number of arguments
 * @argv: pointer to the array with the arguments
 *
 * Return: 0 if succesfull. EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
		error_handler(0, 0, NULL, NULL);
	/*
	 *stack = malloc(sizeof(stack_t));
	 *if (stack == NULL)
	 *  error_handler(3, 0, NULL);
	 */
	fd = openfile(argv[1], &stack);

  freeStack(stack);

	fclose(fd);
	return (0);
}
