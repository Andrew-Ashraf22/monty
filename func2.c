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
