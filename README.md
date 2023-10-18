# 0x19. C - Stacks, Queues - LIFO, FIFO

Zik, verify the addiotion of these if we really need them in addition to what we had before:
-   addnode.c
-   execute.c
-   free_stack (you didn't include it before, I simply created it, but verify it)
-   monty.c (it is the main.c - the programme loop alternative... I didn't see a programme loop, but verify this)
-   queue.c

Please verify or delete what we need. Note the prototypes for keep or delete files:
/* prototypes */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void addqueue(stack_t **head, int n);
void f_stack(stack_t **head, unsigned int counter);
