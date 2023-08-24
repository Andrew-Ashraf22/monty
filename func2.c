#include "monty.h"

void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

void my_swap(stack_t **stack, unsigned int line_number)
{
	int holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	holder = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = holder;
}

void my_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	my_pop(stack, line_number);
}
