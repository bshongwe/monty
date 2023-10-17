#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <unistd.hi>
#include <stdlib.h>
#include <stdio.h>

/* for stack */
extern char *flag;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Task prototypes */
void op_pall(stack **head, unsigned int l_num);
int op_push(stack_t **h, char *line, unsigned int l_num);
stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, int n);

#endif /* end of MONTY_H file */
