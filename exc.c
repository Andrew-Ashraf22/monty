#include "monty.h"

void execute_command(char *com, unsigned int line_count, stack_t **stack)
{
	if (strcmp(com, "push") == 0)
	{
		my_push(stack, line_count);
		return;
	}
	else if (strcmp(com, "pall") == 0)
	{
		my_pall(stack,line_count);
		return;
	}
	else
	{
		fprintf(stderr, "Error: L%d: unknown instruction '%s'\n", line_count, com);
        	exit(EXIT_FAILURE);
	}
}
