#include "monty.h"

void execute_command(char *com, unsigned int line_count, stack_t **stack)
{
	instruction_t inst[5] = {
        {"push", my_push},
        {"pall", my_pall},
	{"pint", my_pint},
	{"pop", my_pop},
	{NULL, NULL},
    };

	int i = 0;
	while ((i < 4))
	{
		if (strcmp(com, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_count);
			break;
		}
		i++;
	}
	if (i >= 4 )
	{
		fprintf(stderr, "Error: L%d: unknown instruction '%s'\n", line_count, com);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
}
