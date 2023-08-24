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
		fprintf(stderr, "Error: L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "Error: L%d: can't pchar, value out of range\n",
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
