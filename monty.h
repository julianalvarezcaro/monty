#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int argument;
int argument;

FILE *openfile(char *pathname, stack_t **stack);
void error_handler(int error_code, int line, char *opcode, char *pathname);
void m_error_handler(int error_code, int line, char *opcode, char *pathname);
void (*get_func(char *opcode))(stack_t **, unsigned int);
char *_null_char(char *entry);
char *_lessSpaces(char *entry);
char *_deleteChar(char *entry, int indx);
void _split(char *text, char **opcode, char **arg);
void validArg(char *arg, int line);
void freeStack(stack_t *stack);

void _push(stack_t **stack, unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _empty(stack_t **stack, unsigned int line);

#endif /* MONTY_H  */
