#include "monty.h"

/**
* i_add - Adds the top two elements of the stack.
* @head: Pointer to the stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_add(stack_t **head, unsigned int counter)
{
stack_t *current;
int stack_length = 0, result;

current = *head;

/* Count the number of elements in the stack */
while (current)
{
current = current->next;
stack_length++;
}

/* Check if there are enough elements in the stack */
if (stack_length < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Add the top two elements of the stack */
current = *head;
result = current->n + current->next->n;
current->next->n = result;
*head = current->next;
free(current);
}


/**
* add_node - Adds a new node to the head of the stack.
* @head: Pointer to the head of the stack.
* @n: Value for the new node.
*
* Return: No return value.
*/
void add_node(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
exit(0);
}

if (aux)
aux->prev = new_node;

new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}


/**
* i_div - Divides the top two elements of the stack.
* @head: Pointer to the stack head.
* @counter: Line number.
* Return: No return value.
*/
void i_div(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

current = *head;

/* Check for division by zero */
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
result = current->next->n / current->n;
current->next->n = result;
*head = current->next;
free(current);
}


/**
* execute - Executes the opcode.
* @content: Line content.
* @stack: Head linked list - stack.
* @counter: Line counter.
* @file: Pointer to the Monty file.
*
* Return: 0 if successful, 1 otherwise.
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", i_push}, {"pall", i_pall}, {"pint", i_pint},
{"pop", i_pop},
{"swap", i_swap},
{"add", i_add},
{"nop", i_nop},
{"sub", i_sub},
{"div", i_div},
{"mul", i_mul},
{"mod", i_mod},
{"pchar", i_pchar},
{"pstr", i_pstr},
{"rotl", i_rotl},
{"rotr", i_rotr},
{"queue", i_queue},
{"stack", i_stack},
{NULL, NULL}
};
unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
