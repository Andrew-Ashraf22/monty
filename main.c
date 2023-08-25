#include "monty.h"
void nothing(void);
inf_s info = {NULL, NULL, NULL};
/**
* main - monty interpreter
* @argc: num of args
* @argv: CLA
* Return: 0 if succ
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execute_file(argv[1], &stack);
	return (0);
}
/**
 * execute_file - exc the file
 *@m_file: monty file
 *@stack: the stack
 */
void execute_file(const char *m_file, stack_t **stack)
{
	unsigned int line_count = 0;
	FILE *file = fopen(m_file, "r");
	char linemax[512];
	char *com = NULL;

	info.mfile = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", m_file);
		exit(EXIT_FAILURE);
	}

	while (fgets(linemax, sizeof(linemax), file))
	{
		line_count++;

		if (linemax[0] == '\n')
			continue;
		com = malloc(sizeof(linemax));

		if (sscanf(linemax, "%s", com) != 1)
		{
			free(com);
			continue;
		}
		info.command = com;
		strtok(linemax, " \n\t");
		info.hold = strtok(NULL, " \n\t");
		execute_command(com, line_count, stack);
		free(com);
	}
	free_stack(stack);
	fclose(file);
}
