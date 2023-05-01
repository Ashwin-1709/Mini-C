typedef struct {
    unsigned int *arr;
    unsigned int len;
} Stack;

unsigned int stackPop(Stack *stack);

void stackPush(Stack *stack, unsigned int val);

Stack *newStack();
