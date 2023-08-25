#include "monty.h"
/**
 *execute_command - execute the current com
 *@com: the command
 *@line_count: num of lines
 *@stack: the stack
 */
void execute_command(char *com, unsigned int line_count, stack_t **stack)
{
	int i = 0;

	instruction_t inst[16] = {
	{"push", my_push},
	{"pall", my_pall},
	{"pint", my_pint},
	{"pop", my_pop},
	{"swap", my_swap},
	{"add", my_add},
	{"nop", my_nop},
	{"sub", my_sub},
	{"div", my_div},
	{"mul", my_mul},
	{"mod", my_mod},
	{"pchar", my_pchar},
	{"pstr", my_pstr},
	{"rotr", my_rotr},
	{"rotl", my_rotl},
	{NULL, NULL},
	};

	while ((i < 15))
	{
		if (strcmp(com, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_count);
			break;
		}
		i++;
	}
	if (i >= 15)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, com);
		free_stack(stack);
		free_info();
		exit(EXIT_FAILURE);
	}
}
