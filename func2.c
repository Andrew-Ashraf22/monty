#include "monty.h"

/**
 *my_pop - remove top element
 *@stack: the stack
 *@line_number: num of lines
 */
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

/**
 *my_swap - swap top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
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

/**
 *my_add - add top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
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

/**
 *my_nop - do nothing
 *@stack: useless
 *@line_number: useless
 */
void my_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;
}

/**
 *my_sub - sub top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
void my_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	my_pop(stack, line_number);
}

/**
 *my_div - div top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "Error: L%d: division by zero\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	my_pop(stack, line_number);
}
/**
 *my_mul - mul top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
void my_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	my_pop(stack, line_number);
}
/**
 *my_mod - mod top 2 items
 *@stack: the stack
 *@line_number: num of lines
 */
void my_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "Error: L%d: division by zero\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	my_pop(stack, line_number);
}
