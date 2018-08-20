#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define LOWPRIORITY 0
#define HIGHPRIORITY 2
#define SIZE 50
#define MULTIPLIER 2

typedef struct Stack{
    char *stack_Data;
    int size;
    int top;
}Stack_t;

void push(Stack_t *myStack, const char symb);
char pop(Stack_t *myStack);
char getTop(Stack_t *myStack);
bool isEmpty(Stack_t *myStack);
bool isOperand(const char symb);
bool isOperator(const char symb);
char *parseInput(Stack_t * myStack, const char *infix, const int length);
bool getPriority(const char symb);
void resize(Stack_t *myStack);
Stack_t * createStack(void);

#endif
