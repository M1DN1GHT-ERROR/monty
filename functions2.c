#include "monty.h"

/**
* i_pall - Prints the stack.
* @head: Stack head.
* @counter: Line number (not used).
*
* Return: No return value.
*/
void i_pall(stack_t **head, unsigned int counter)
{
stack_t *current;
(void) counter;

current = *head;
if (current == NULL)
return;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}


/**
* i_pchar - Prints the character at the top of the stack,
*		followed by a new line.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_pchar(stack_t **head, unsigned int counter)
{
stack_t *current;

current = *head;
if (!current)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

if (current->n > 127 || current->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

printf("%c\n", current->n);
}

/**
* i_pint - Prints the value at the top of the stack.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
* i_pop - Removes the top element of the stack.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_pop(stack_t **head, unsigned int counter)
{
stack_t *current;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

current = *head;
*head = current->next;
free(current);
}

