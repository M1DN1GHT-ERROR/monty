#include "monty.h"

/**
 * get_mul - Function that multiplies the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation occurs
 *
 */
void get_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		next = top->next;
		next->n *= top->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(top);
	}
}

