#include "monty.h"

/**
 * op_pop - func pulls element frm stack
 * @h: dll pointer
 * @l_num: line number
 * Return: void
 */
void op_pop(stack_t **h, unsigned int l_num)
{
	stack_t *node;

	node = pop_s(h);

	if (node == NULL)
	{
		printf("L%d: can't pop an empty stack %s\n", l_num, flag);
		free_stackk(*h);
		exit(EXIT_FAILURE);
	}
	free(node);
}

/**
 * swap - swap the values of the top and last elements
 * @h: head of the dll
 * @l: line number
 * opcode: swap
 */
void swap(stack_t **h, unsigned int l)
{
	int value0;

	if (!h || !*h)
	{
		printf("L%d: can't swap, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	value0 = (*h)->n;

	if ((*h)->next == NULL)
	{
		printf("L%d: can't swap, %s too short\n", l, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	(*h)->n = ((*h)->next)->n;
	((*h)->next)->n = value0;
}
