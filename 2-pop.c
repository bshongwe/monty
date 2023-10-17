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
 * op_swap - func swaps first and last elements' values
 * @h: dll head
 * @l: line number
 * Return: void
 */
void op_swap(stack_t **h, unsigned int l_num)
{
	int value0;

	if (!h || !*h)
	{
		printf("L%d: can't swap, %s too short\n", l_num, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	value0 = (*h)->n;

	if ((*h)->next == NULL)
	{
		printf("L%d: can't swap, %s too short\n", l_num, flag);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	(*h)->n = ((*h)->next)->n;
	((*h)->next)->n = value0;
}
