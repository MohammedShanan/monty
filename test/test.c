#include "test.h"
int main(int argc, char *argv[])
{
FILE *f;
if (argc != 2)
{
write(2, "USAGE: monty file\n", 18);
exit(EXIT_FAILURE);
}
f = fopen(argv[1], "r");
if (f == NULL)
{
write(2, "Error: Can't open file", 23);
write(2, argv[1], strlen(argv[1]));
write(2, "\n", 1);
exit(EXIT_FAILURE);
}
interpreter(f);
return (0);
}

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

size_t dlistint_len(stack_t *h)
{
size_t nodes;
nodes = 0;
while (h)
{
h = h->next;
nodes++;
}
return (nodes);
}

size_t print_dlistint(stack_t *h)
{
size_t nodes;
nodes = 0;
while (h)
{
printf("%d\n", h->n);
h = h->next;
nodes++;
}
return (nodes);
}

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

void _error(char *msg, int line_num)
{
status = EXIT_FAILURE;
fprintf(stderr, "L%i%s\n", line_num, msg);
}

void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
_error(": can't pint, stack empty", line_number);
return;
}
printf("%i\n", (*stack)->n);
}

void push(stack_t **stack, unsigned int line_num, char *arg, char id)
{
if (is_num(arg) == -1)
{
_error(": usage: push integer", line_num);
return;
}
if (id == 'q')
{
add_dnodeint_end(stack, atoi(arg));
}
else
{
add_dnodeint(stack, atoi(arg));
}
}

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (*stack == NULL)
{
_error(": can't pop, stack empty", line_number);
return;
}
tmp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
{
(*stack)->prev = NULL;
}
free(tmp);
}

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *h;
h = *stack;
(void)line_number;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't swap, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node1->next = node2->next;
node1->prev = node2;
node2->next = node1;
node2->prev = NULL;
*stack = node2;
}

void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
return;
}

void add(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't add, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n + node1->n;
pop(stack, line_number);
}

void sub(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't sub, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n - node1->n;
pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't mul, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n * node1->n;
pop(stack, line_number);
}

void _div(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't div, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
if (node1->n == 0)
{
_error(": division by zero", line_number);
return;
}
node2->n = node2->n / node1->n;
pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't mod, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
if (node1->n == 0)
{
_error(": division by zero", line_number);
return;
}
node2->n = node2->n / node1->n;
pop(stack, line_number);
}

void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
_error(": can't pchar, stack empty", line_number);
return;
}
if ((*stack)->n >= 0 && (*stack)->n <= 127)
{
printf("%c\n", (*stack)->n);
}
else
{
_error(": can't pchar, value out of range", line_number);
return;
}
}

void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
tmp = *stack;
(void)line_number;
while (tmp)
{
if ((tmp->n < 0 || tmp->n > 127) || tmp->n == 0)
{
break;
}
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *top_node;
top_node = tmp = *stack;
(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
while (tmp->next)
{
tmp = tmp->next;
}
*stack = (*stack)->next;
(*stack)->next->prev = NULL;
top_node->next = NULL;
top_node->prev = tmp;
tmp->next = top_node;
}

void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *top_node;
top_node = tmp = *stack;
(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
while (tmp->next)
{
tmp = tmp->next;
}
*stack = tmp;
tmp->prev->next = NULL;
tmp->prev = NULL;
top_node->prev = tmp;
tmp->next = top_node;
}

void check_status(FILE *f, char *buff, stack_t *stack)
{
if (status == EXIT_FAILURE)
{
fclose(f);
free_dlistint(stack);
free(buff);
exit(EXIT_FAILURE);
}
}

void interpreter(FILE *f)
{
char *buff;
stack_t *stack = NULL;
size_t n;
unsigned int line_num = 1;
buff = NULL;
while (getline(&buff, &n, f) != -1)
{
parse_line(buff, line_num, &stack);
check_status(f, buff, stack);
line_num++;
free(buff);
buff = NULL;
}
fclose(f);
free(buff);
free_dlistint(stack);
}

void (*get_op_func(char *token))(stack_t **stack, unsigned int line_number)
{
instruction_t ops[] = {{"pop", pop},
{"pall", pall},
{"pint", pint},
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

void parse_line(char *line, unsigned int line_num, stack_t **stack)
{
char *opcode, *arg;
static char id = 's';
void (*fun)(stack_t * *stack, unsigned int line_number);
opcode = strtok(line, " \n");
arg = strtok(NULL, " \n");
if (strcmp("queue", opcode) == 0 || strcmp("stack", opcode) == 0)
{
id = strcmp("queue", opcode) == 0 ? 'q' : 's';
}
else if (strcmp("push", opcode) == 0)
{
push(stack, line_num, arg, id);
}
else
{
fun = get_op_func(opcode);
if (fun == NULL)
{
status = EXIT_FAILURE;
fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);
}
else
{
fun(stack, line_num);
}
}
}

char *remove_spaces(char *str)
{
    int i = 0;
    while (*str == ' ')
    {
        str++;
    }
    return (str);
}