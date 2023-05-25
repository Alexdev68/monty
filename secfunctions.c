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
	int count = 0;

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
	second->n =  (second->n / top->n);
	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
/**
 * mul - This function divides the top 2 elements of a stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *top;
	stack_t *second;
	int count = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;

	second->n =  (second->n * top->n);
	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
/**
 * mod - This function divides the top 2 elements of a stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *top;
	stack_t *second;
	int count = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n =  (second->n % top->n);
	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * pchar - This function prints the char at the top of the stack
 * @stack: This is a pointer to the top of the stack
 * @line_number: This is the current line in which the opcode is found
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 && (*stack)->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}


void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->n == 0)
		{
			putchar('\n');
			exit(EXIT_FAILURE);
		}
		if (current->n < 0 && current->n > 255)
		{
			putchar('\n');
			exit(EXIT_FAILURE);
		}
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
