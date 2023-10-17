#include "monty.h"

/**
 * op_pall - func prints all elements in dll as numbers
 * @head: dll pointer
 * @l_num: line of number
 * Return: void
 */
void op_pall(stack **head, unsigned int l_num)
{
	stack_t *h;
	(void) l_num;

	if (!head)
	{
		return;
	}
	h = *head;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * op_push - func adds an element to stack
 * @h: dll pointer
 * @line: line pointer
 * @l_num: line of number
 * Return: Success (0), fail (-1)
 */
int op_push(stack_t **h, char *line, unsigned int l_num)
{
	char *start_n;
	stack_t *node;

	start_n = reach_number(line);
	if (start_n == NULL)
	{
		printf("L%d: usage: push integer\n", l_num);
		free(line);
		return (-1);
	};

	if (_strcmp(flag, "stack") == 0)
	{
		node = add_node(h, atoi(start_n));
	}
	else
	{
		node = add_node_end(h, atoi(start_n));
	}

	gree(line);
	if (node == NULL)
	{
		put("Error: malloc failed");
		return (-1);
	}
	return (0);
}
