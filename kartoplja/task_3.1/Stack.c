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

bool isOperand(const char symb)
{
    if (symb >= '0' && symb <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOperator(const char symb)
{
    if (symb == '+' || symb == '-' || symb == '*' || symb == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *parseInput(Stack_t * myStack, const char *infix, const int length)
{
    int i;
    int j = 0;
    char current;
    char *postfix = (char*)calloc(MULTIPLIER * length, sizeof(char));

    for (i = 0; i < length; i++)
    {
        current = infix[i];

        if (current == '(')
        {
            push(myStack, current);
            continue;
        }
        else if (isOperand(current))
        {
            postfix[j] = current;
            postfix[j+1] = ' ';
            j += 2;
            continue;
        }
        else if (isOperator(current))
        {
            while (isOperator(getTop(myStack)))
            {
                if (getPriority(current) <= getPriority(getTop(myStack)))
                {
                    postfix[j] = pop(myStack);
                    postfix[j+1] = ' ';
                    j += 2;
                    continue;
                }
                else
                {
                    break;
                }
            }

            push(myStack, current);

            continue;
        }
        else if (current == ')')
        {
            while (getTop(myStack) != '(')
            {
                postfix[j] = pop(myStack);
                postfix[j+1] = ' ';
                j += 2;
            }
            pop(myStack);
        }
        else
        {
            continue;
        }
    }
    return postfix;
}

bool getPriority(char symb)
{
    if(symb == '+' || symb == '-')
    {
        return LOWPRIORITY;
    }
    else
    {
        return HIGHPRIORITY;
    }
}


void resize(Stack_t *myStack)
{
    myStack->size *= MULTIPLIER;
    myStack->stack_Data = realloc(myStack->stack_Data, myStack->size * sizeof(char));

}
