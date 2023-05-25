#include "monty.h"

char *op_val;

/**
 * main - This is the entry point
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * Return: This returns 0 on success and exits with EXIT_SUCCESS on failure
 */
int main(int argc, char **argv)
{
	char buff[1024];
	FILE *ptr;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buff, sizeof(buff), ptr) != NULL)
	{
		line_number++;
		opcode = strtok(buff, " \t\n");
		if (!opcode || strcmp(opcode, "nop") == 0)
			continue;
		if (opcode[0] == '#')
			continue;

		op_val = strtok(NULL, " \t\n");

		fnd_func(opcode, line_number)(&stack, line_number);
	}
	fclose(ptr);
	free_stack(stack);
	return (0);
}

/**
 * *fnd_func - This function finds the corresponding
 * function based on the opcode given
 *
 * @s: This contains the opcode gotten from a .m file
 * @line: This is the current line of the file
 * Return: This returns a pointer to the function the corresponds
 * with the opcode
 */
void (*fnd_func(char *s, unsigned int line))(stack_t **, unsigned int)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, s);
	exit(EXIT_FAILURE);
}

/**
 * push - This function pushes values unto the stack
 * @stack: This is a pointer to the top of the stack
 * @line_number: This is the current line of the file being read from
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int value;
	int i = 0;
	char *val = op_val;

	if (val == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (val)
	{
		if (val[i] == '-')
			i++;
		for (; val[i]; i++)
		{
			if (val[i] > 57 || val[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	value = atoi(val);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = (*stack);

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	(*stack) = new;
}

/**
 * pall - This function prints all the values of the stack out
 * @stack: This is a pointer to the top of the stack
 * @line_number: This is the current line of the file being read from
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - This function frees all allocated memory of the stack_t
 * @stack: This is a pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
