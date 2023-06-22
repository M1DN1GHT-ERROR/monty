#include "monty.h"

/**
* i_rotl - Rotates the stack to the top.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}

/**
* i_rotr - Rotates the stack to the bottom.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *copy;

copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}

/**
* i_stack - Switches the stack behavior to LIFO (stack mode).
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_stack(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 0;
}

/**
* i_sub - Subtracts the top element of the stack from the second top element.
* @head: Stack head
* @counter: Line number
*
* Return: No return value
*/
void i_sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int result, num_nodes;

aux = *head;
for (num_nodes = 0; aux != NULL; num_nodes++)
aux = aux->next;
if (num_nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
result = aux->next->n - aux->n;
aux->next->n = result;
*head = aux->next;
free(aux);
}
