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
 * swap - This function swaps the top two functions on the stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;

	top->prev = second;
	top->next = second->next;
	second->prev = NULL;
	second->next = top;

	if (top->next != NULL)
	{
		top->next->prev = top;
	}
	*stack = second;
}

/**
 * add - This function adds the top 2 elements of a stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *top;
	stack_t *second;
	int count = 0;
	int sum = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = (*stack)->next;

	sum += (top->n + second->n);

	second->n = sum;

	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
/**
 * sub - This function subtracts the top 2 elements of a stack
 * @stack: This is a double pointer to the top of the stack
 * @line_number: The number at the which the opcode is found
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *top;
	stack_t *second;
	int count, sub = 0;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;
	sub -= (top->n - second->n);
	second->n = sub;

	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
