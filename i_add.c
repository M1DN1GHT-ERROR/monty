#include "monty.h"

/**
 * get_add - Function that adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation occurs
 *
 * Description: This function adds the top two elements of the stack.
 * Return: Nothing on success, or exits with failure status.
 */
void get_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		next = top->next;
		next->n += top->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(top);
	}
}


