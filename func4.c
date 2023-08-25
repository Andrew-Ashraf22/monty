#include "monty.h"
/**
 * my_rotl - rotate the stack
 *@stack: the stack
 *@line_number: num of lines
 */
void my_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *l = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (l->next != NULL)
		l = l->next;

	l->next = *stack;
	(*stack)->prev = l;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * my_rotr - rotate the stack to bottom
 *@stack: the stack
 *@line_number: num of lines
 */
void my_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *l = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (l->next != NULL)
		l = l->next;

	l->next = *stack;
	(*stack)->prev = l;
	*stack = l;
	l->prev->next = NULL;
	l->prev = NULL;
}
