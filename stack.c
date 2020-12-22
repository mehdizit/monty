#include "monty.h"
/**
 * push - add new item to top of stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * @n: value of new item on stack
 * Return: void, exit with -1 on failure
 */
void push(stack_t **stack, unsigned int line_number, char *c )
{

	int i;
	stack_t *new = NULL;

	if (c == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[0] == '-' && i == 0)
			continue;
		if (isdigit(c[i] == 0))
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	new->n = atoi(c);
	new->prev = NULL;
	new->next = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
	
				
/**
 * pall - prints the value of all items on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - prints value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int i;
	
	if (stack == NULL || *stack == NULL)
	{
		printf("L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	printf("%d\n", i);
}
/**
 * pop - remove item at the top of stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void, exit with -1 on failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	free(*stack);
	*stack = next;
}
/**
 * swap - swaps the value of the top two elements on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void, exit with -1 on failure
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp1;
	int tmp2;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack)->n;
	tmp2 = (*stack)->next->n;

	(*stack)->n = tmp2;
	(*stack)->next->n = tmp1;
}
/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	int i, j, add;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	j = (*stack)->next->n;

	add = i + j;

	pop(stack, line_number);

	(*stack)->n = add;
}

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
