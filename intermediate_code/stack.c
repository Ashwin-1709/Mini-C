#include "stack.h"
#include <stdlib.h>
#include <string.h>

unsigned int stackPop(Stack *stack) {
    unsigned int ans = stack->arr[stack->len - 1];
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

char *charStackPop(charStack *stack) {
    char *ans = stack->arr[stack->len - 1];
    stack->len--;
    return ans;
}

void charStackPush(charStack *stack, char *val) {
    strcpy(stack->arr[stack->len], val);
    stack->len++;
}

charStack *newCharStack() {
    char **arr = (char **)malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++) {
        char *str = (char *)calloc(1000, sizeof(char));
        arr[i] = str;
    }
    charStack *stack = malloc(sizeof(charStack));
    stack->arr = arr;
    stack->len = 0;
    return stack;
}
