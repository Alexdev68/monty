#include "monty.h"
/**
 * division- This function divides the top 2 elements of a stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *top;
	stack_t *second;
	int count = 0, div = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div /= (top->n / second->n);
	second->n = div;
	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
