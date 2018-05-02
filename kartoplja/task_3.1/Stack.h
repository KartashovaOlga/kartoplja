#ifndef STACK_H
#define STACK_H

#define LOWPRIORITY 1
#define HIGHPRIORITY 2
#define MAXSIZE 50

typedef struct stack{
    char stackArr[MAXSIZE];
    int top;
}Stack_t;

void push(Stack_t *myStack, char symb);
char pop(Stack_t *myStack);
char getTop(Stack_t *myStack);
int isEmpty(Stack_t *myStack);
int isOperand(char symb);
int isOperator(char symb);
char *parseInput(Stack_t * myStack, char *infix, int length);
int getPriority(char symb);

#endif
