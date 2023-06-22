#include "monty.h"

/**
 * get_div - Function that divides the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation occurs
 *
 * Description: This function divides the second element on top of the stack
 *              by the top element.
 * Return: Nothing on success, or exits with failure status.
 */
void get_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(file);
		free(*stack);
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
		next->n /= top->n;
		*stack = next;
		(*stack)->prev = NULL;
		free(top);
	}
}

