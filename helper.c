#include "monty.h"
/**
 * add_dnodeint - add node to front of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null if failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *new_node;
if (head == NULL)
{
return (NULL);
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
if (*head == NULL)
{
new_node->next = NULL;
new_node->prev = NULL;
*head = new_node;
return (new_node);
}
new_node->prev = NULL;
new_node->next = *head;
(*head)->prev = new_node;
*head = new_node;
return (new_node);
}

/**
 * free_dlistint - frees a doubly linked list with only int data, no strings
 * @head: pointer to head of list
 */
void free_dlistint(stack_t *head)
{
stack_t *tmp;
tmp = head;
while (tmp)
{
head = head->next;
free(tmp);
tmp = head;
}
}

/**
 * add_dnodeint_end - add node to end of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null if failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *new_node, *tmp;
if (head == NULL)
{
return (NULL);
}
tmp = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
if (*head == NULL)
{
*head = new_node;
new_node->next = NULL;
new_node->prev = NULL;
return (new_node);
}
while (tmp->next)
{
tmp = tmp->next;
}
tmp->next = new_node;
new_node->prev = tmp;
new_node->next = NULL;
return (new_node);
}
/**
 * is_num - check if the string is a number or not
 * @n: string
 * Return: 1 if string is  a number 0 if not
 */
int is_num(char *n)
{
int i = 0;
while (n[i])
{
if (n[i] > '9' || n[i] < '0')
{
return (-1);
}
i++;
}
return (1);
}
/**
 * get_op_func - get the proper function for the opcode
 * @token: opcode
 * Return: a function pointer or NULL
 */
void (*get_op_func(char *token))(stack_t **stack, unsigned int line_number)
{
instruction_t ops[] = {{"pop", pop},
{"pall", pall},
{"pint", pint},
{"nop", nop},
{"swap", swap},
{"add", add},
{"sup", sub},
{"mul", mul},
{"div", _div},
{"mod", mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}};
int i = 0;
while (ops[i].opcode)
{
if (strcmp(token, ops[i].opcode) == 0)
{
return (ops[i].f);
}
i++;
}
return (NULL);
}
