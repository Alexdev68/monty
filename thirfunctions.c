#include "monty.h"
/**
 * rotl - This function rotates the stack to the top
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;
	stack_t *last;
	stack_t *current = *stack;
	int count = 0;
	(void)line_number;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't rotl, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = top;
	top->prev = last;
	*stack = second;
	second->prev = NULL;
	top->next = NULL;
}
/**
 * rotr - This function rotates the stack to the bottom
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *current = *stack;
	int count = 0;
	(void)line_number;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't rotr, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
