#include "monty.h"
/**
* main - monty interpreter
* @argc: num of args
* @argv: CLA
* Return: 0 if succ
*/
void execute_file(const char *m_file, stack_t **stack);

inf_s info = {NULL, NULL};
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	execute_file(argv[1], &stack);
	exit(EXIT_SUCCESS);
}

void execute_file(const char *m_file, stack_t **stack)
{
	unsigned int line_count = 0;
	FILE *file = fopen(m_file, "r");
	char linemax[512];
	char *com = NULL;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", m_file);
		exit(EXIT_FAILURE);
	}

	while (fgets(linemax, sizeof(linemax), file))
	{
		line_count++;
		if (linemax[0] == '\n')
		{
			continue;
		}
		com = malloc(sizeof(linemax));
		if (sscanf(linemax, "%s", com) != 1)
		{
			fprintf(stderr, "Error: L%d: Invalid instruction format\n", line_count);
			exit(EXIT_FAILURE);
		}
		strtok(linemax, " \n\t");
		info.hold = strtok(NULL, " \n\t");
		execute_command(com, line_count, stack);
		free(com);
	}
	fclose(file);
}
