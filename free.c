#include "monty.h"
/**
* free_stack - frees the stack
* @head: the stack
*/
void free_stack(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}

void free_info(void)
{
	free(info.command);
	fclose(info.mfile);
}
