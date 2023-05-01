#include "stack.h"
#include <stdlib.h>

unsigned int stackPop(Stack *stack) {
    unsigned int ans = stack->arr[stack->len];
    stack->len--;
    return ans;
}

void stackPush(Stack *stack, unsigned int val) {
    stack->arr[stack->len] = val;
    stack->len++;
}

Stack *newStack() {
    unsigned int *arr = (unsigned int *)malloc(1000 * sizeof(unsigned int));
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = arr;
    stack->len = 0;
    return stack;
}
