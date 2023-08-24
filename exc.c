#include "monty.h"

void execute_command(char *com, unsigned int line_count, stack_t **stack)
{
	instruction_t inst[] = {
        {"push", my_push},
        {"pall", my_pall},
    };

	int i = 0;
	while ((long unsigned int)i < sizeof(inst) / sizeof(inst[0]))
	{
		if (strcmp(com, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_count);
			break;
		}
		i++;
	}
	if ((long unsigned int )i >= sizeof(inst) / sizeof(inst[0]))
	{
		fprintf(stderr, "Error: L%d: unknown instruction '%s'\n", line_count, com);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
}
