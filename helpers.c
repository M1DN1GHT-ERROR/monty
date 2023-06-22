/**
* i_pstr - Prints the string starting at the top of the stack,
*          followed by a new line.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_pstr(stack_t **head, unsigned int counter)
{
stack_t *current;
(void) counter;

current = *head;
while (current)
{
if (current->n > 127 || current->n <= 0)
{
break;
}
printf("%c", current->n);
current = current->next;
}
printf("\n");
}

/**
* i_push - Adds a new node to the stack.
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > '9' || bus.arg[j] < '0')
	flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

n = atoi(bus.arg);
if (bus.lifi == 0)
addnode(head, n);
else
addqueue(head, n);
}

/**
* i_queue - Sets the stack mode to queue (add to the tail).
* @head: Stack head.
* @counter: Line number.
*
* Return: No return value.
*/
void i_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifo = 0;
}

/**
* addqueue - Adds a new node to the tail of the stack.
* @head: Pointer to the head of the stack.
* @n: Value to be added.
*
* Return: No return value.
*/
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (aux)
{
while (aux->next)
aux = aux->next;
}
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}
