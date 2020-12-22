#include "monty.h"
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	j = (*stack)->next->n;

	add = i + j;

	pop(stack, line_number);

	(*stack)->n = add;
}
/**
 * _sub - substracts the top element of the stack from the second.
 * @stack: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
 * _div - divides the second top element of the stack by the top element.
 * @stack: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
/**
 * _mul - multiplies the second top element of the stack with the top element.
 * @stack: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
 * _mod - computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (*stack)
			free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
