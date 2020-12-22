#include "monty.h"
/**
 *main - entred point
 *@argc: integer
 *@argv: char pointer
 *Return: success otherwise error or failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	char *line = NULL;
	unsigned int line_number;
	char *opcode;
	char *n;
	size_t len = 0;
	ssize_t read;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	line_number = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
	
		line_number++;
	
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			push(&stack, line_number, n);
		}
		else
			opcode_struct(opcode, &stack, line_number);
	}

	free_all(stack, line, fp);
	return (EXIT_SUCCESS);
}
			
