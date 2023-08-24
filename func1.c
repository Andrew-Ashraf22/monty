#include "monty.h"
/**
 *my_push - push to stack
 *@stack: the stack
 *@line_number: num of lines
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	char *hold = info.hold;
	int n, i = 0;

	if (!hold || strcmp(hold, "-") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}

	if (hold[0] == '-')
		i++;
	for (; (size_t)i < strlen(hold); i++)
	{
		if (hold[i] > 57 || hold[i] < 48)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			free_info();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(hold);
	addnode(stack, n);
}
/**
 * addnode - add node to stack
 * @stack: the stack
 * @n: the stack n
 */
void addnode(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 *my_pall - show list
 *@stack: the stack
 *@line_number: num of lines
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *my_pint - prints top of a stack
 *@stack: the stack
 *@line_number: num of lines
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

