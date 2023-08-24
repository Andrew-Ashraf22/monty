#include "monty.h"

void execute_command(char *com, unsigned int line_count, stack_t **stack)
{
	instruction_t inst[7] = {
        {"push", my_push},
        {"pall", my_pall},
	{"pint", my_pint},
	{"pop", my_pop},
	{"swap", my_swap},
	{"add", my_add},
	{NULL, NULL},
    };

	int i = 0;
	while ((i < 6))
	{
		if (strcmp(com, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_count);
			break;
		}
		i++;
	}
	if (i >= 6)
	{
		fprintf(stderr, "Error: L%d: unknown instruction '%s'\n", line_count, com);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
}
