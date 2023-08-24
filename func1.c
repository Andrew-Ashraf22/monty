#include "monty.h"

void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	
	if (strcmp(info.hold, "0") != 0)
	{
		new->n = atoi(info.hold);
	
		if (new->n == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			free_info();
			free(new);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		info.hold = 0;
		new->n = 0;
	}
	new->prev = NULL;

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

