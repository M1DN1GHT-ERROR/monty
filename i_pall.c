#include "monty.h"

/**
 * get_pall - Print all elements in the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Return: Nothing on success, or exits with failure status.
 */
void get_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

#include "monty.h"

/**
 * get_pchar - Print the character at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Return: Nothing on success, or exits with failure status.
 */
void get_pchar(stack_t **stack, unsigned int line_number)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(isascii((*stack)->n)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}


#include "monty.h"

/**
 * get_pint - Print the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Return: Nothing on success, or exits with failure status.
 */
void get_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

