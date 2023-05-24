#include "monty.h"
/**
 * pint - This function prints the value on top of the stack
 * @stack: A double pointer to the head of the stack
 * @line_number: The number at the which the node is found
 * @val: A pointer to character value
 */
void pint(stack_t **stack, unsigned int line_number, char *val)
{
	(void)val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
