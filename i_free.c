#include "monty.h"

/**
 * get_free - Frees the stack
 * @stack: Pointer to the stack
 *
 * Description: This function recursively frees the memory allocated for each
 *              element in the stack.
 * Return: Void
 */
void get_free(stack_t *stack)
{
	if (stack)
	{
		get_free(stack->next);
		free(stack);
	}
}

