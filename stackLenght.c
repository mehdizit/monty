#include "monty.h"

/**
 * stack_length - returns length of stack
 * @stack: pointer to head of stack
 * Return: length of stack
 */
size_t stack_length(stack_t **stack)
{
	stack_t *count;
	unsigned int len;

	count = *stack;
	len = 0;
	while (count != NULL)
	{
		count = count->next;
		len++;
	}

	return (len);
}
