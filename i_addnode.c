#include "monty.h"

/**
 * addnode - Adds a node to the head of the stack.
 * @head: Head of the stack
 * @n: New value
 * Return: No return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current)
	{
		current->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
