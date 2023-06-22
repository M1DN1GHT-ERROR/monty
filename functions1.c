#include "monty.h"

/**
* free_stack - Frees a doubly linked list.
* @head: Pointer to the head of the stack.
*
* Description: This function frees the memory allocated for a doubly linked
* list starting from the given head node.
*
* Return: None.
*/
void free_stack(stack_t *head)
{
stack_t *aux;

aux = head;

while (head)
{
aux = head->next;
free(head);
head = aux;
}
}

/**
* i_mod - Computes the remainder of the division of the second
*         top element of the stack by the top element of the stack.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_mod(stack_t **head, unsigned int counter)
{
stack_t *current;
int stack_len = 0, remainder;

current = *head;
while (current)
{
current = current->next;
stack_len++;
}

if (stack_len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

current = *head;
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

remainder = current->next->n % current->n;
current->next->n = remainder;
*head = current->next;
free(current);
}

/**
* i_mul - Multiplies the top two elements of the stack.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_mul(stack_t **head, unsigned int counter)
{
stack_t *current;
int stack_len = 0, result;

current = *head;
while (current)
{
current = current->next;
stack_len++;
}

if (stack_len < 2)
{
fprintf(stderr, "L%d: can't multiply, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

current = *head;
result = current->next->n * current->n;
current->next->n = result;
*head = current->next;
free(current);
}

/**
* i_nop - Does nothing.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_nop(stack_t **head, unsigned int counter)
{
(void)counter;
(void)head;
}
