#include "monty.h"

/**
 * get_mod - Function that calculates the modulus of the top two elements
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation occurs
 *
 * Return: Nothing on success, or exits with failure status.
 */
void get_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		next = top->next;
		next->n %= top->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(top);
	}
}

