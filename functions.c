#include "monty.h"
/**
 * pint - This function prints the value on top of the stack
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - This function removes the top element of the stack
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);

}
/**
 * nop - This function does absolutely nothing
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
