#include "monty.h"
/**
  * my_pchar - print char at top
  *@stack: the stack
  *@line_number: num of lines
  */
void my_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
		line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
  * my_pstr - print string from top
  *@stack: the stack
  *@line_number: number of lines
  */
void my_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 &&
	current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	my_pop(stack, line_number);
}
