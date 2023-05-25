#include "monty.h"
/**
 * rotl - This function prints the value on top of the stack
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second, *last;
	(void)line_number;

	top = *stack;
	second = top->next;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = top;
	top->prev = last;
	*stack = second;
	second->prev = NULL;
	top->next = NULL;
}
