#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void push(Stack_t *myStack, char symb)
{
    myStack->stackArr[myStack->top] = symb;
    myStack->top++;
}

char pop(Stack_t *myStack)
{
    if (isEmpty(myStack) > 0)
    {
        myStack->top--;
        return myStack->stackArr[myStack->top];
    }
    else
    {
        printf("Stack is empty\n");
    }
}

char getTop(Stack_t *myStack)
{
    if (isEmpty(myStack) > 0) {
        return myStack->stackArr[myStack->top - 1];
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int isEmpty(Stack_t *myStack)
{
    if (myStack->top > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int isOperand(char symb)
{
    if (symb >= '0' && symb <= '9')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int isOperator(char symb)
{
    if (symb == '+' || symb == '-' || symb == '*' || symb == '/')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char *parseInput(Stack_t * myStack, char *infix, int length)
{
    int i;
    int j = 0;
    char current;
    char *postfix = (char*)calloc(length * 2, 1);

    for (i = 0; i < length; i++)
    {
        current = infix[i];

        if (current == '(')
        {
            push(myStack, current);
            continue;
        }
        else if (isOperand(current) > 0)
        {
            postfix[j] = current;
            j++;
            postfix[j] = ' ';
            j++;
            continue;
        }
        else if (isOperator(current) > 0)
        {
            while (isOperator(getTop(myStack)) > 0)
            {
                if (getPriority(current) <= getPriority(getTop(myStack)))
                {
                    postfix[j] = pop(myStack);
                    j++;
                    postfix[j] = ' ';
                    j++;
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
                j++;
                postfix[j] = ' ';
                j++;
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

int getPriority(char symb)
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