#include "monty.h"
/**
 *free_dlistint - free all node of linked list
 *@head: head linked list
 *Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
