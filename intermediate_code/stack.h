typedef struct {
    unsigned int *arr;
    unsigned int len;
} Stack;

unsigned int stackPop(Stack *stack);

void stackPush(Stack *stack, unsigned int val);

Stack *newStack();

typedef struct {
    char **arr;
    unsigned int len;
} charStack;

char *charStackPop(charStack *stack);

void charStackPush(charStack *stack, char *val);

charStack *newCharStack();
