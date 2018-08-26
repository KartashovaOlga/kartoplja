#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack_t *createStack(void)
{
    Stack_t *myStack = NULL;

    myStack = malloc(sizeof(Stack_t));
    myStack->size = SIZE;
    myStack->stack_Data = calloc(myStack->size, sizeof(char));
    myStack->top = 0;

    return myStack;
}

void push(Stack_t *myStack, const char symb)
{
    if(myStack->top == myStack->size)
    {
        resize(myStack);
    }
    myStack->stack_Data[myStack->top] = symb;
    myStack->top++;
}

char pop(Stack_t *myStack)
{
    if (isEmpty(myStack))
    {
        myStack->top--;
        return myStack->stack_Data[myStack->top];
    }
    else
    {
        printf("Stack is empty\n");
    }
}

char getTop(Stack_t *myStack)
{
    if (isEmpty(myStack)) {
        return myStack->stack_Data[myStack->top - 1];
    }
    else
    {
        printf("Stack is empty\n");
    }
}

bool isEmpty(Stack_t *myStack)
{
    if (myStack->top > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void resize(Stack_t *myStack)
{
    myStack->size *= MULTIPLIER;
    myStack->stack_Data = realloc(myStack->stack_Data, myStack->size * sizeof(char));

}