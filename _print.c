#include "main.h"
/**
 * _print - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _print(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
