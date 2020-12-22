#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (stack)
			free(*stack);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;
	if ((c < 0) || (c > 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}
/**
 *pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	int c;

	while (*stack != NULL)
	{
		c = (*stack)->n;
		if (c > 0 && c <= 127)
		{
			(*stack) = (*stack)->next;
			putchar(c);
		}
		else
			break;
	}
	putchar('\n');
}
