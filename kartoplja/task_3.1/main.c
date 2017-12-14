/*
Напишите  модуль,  реализующий  структуру  данных  «Стек»  с  элементами  типа  char.
Реализуйте следующие операции: помещение значения в стек, извлечение значения из  стека,
просмотр значения в верхнем элементе стека без его извлечения, проверка стека  на пустоту.

Входные данные: в файле в одной строке записано выражение.
Выходные данные: в файл записать выражение в польской записи.
*/

#include <stdio.h>
#include <malloc.h>
#include <mem.h>

#define MAXSIZE 50
#define LOWPRIORITY 1
#define HIGHPRIORITY 2
typedef struct{
    char stackArr[MAXSIZE];
    int top;
}stack;

char * readFromFile(void);
void push(stack *myStack, char symb);
char pop(stack *myStack);
char getTop(stack *myStack);
int isEmpty(stack *myStack);
int isOperand(char symb);
int isOperator(char symb);
void writeToFile(char  *postfix, int length);
char *parseInput(stack * myStack, char *infix, int length);
int getPriority(char symb);

int main(int argc, char **argv)
{
    int length;

    char *infix = readFromFile();
    length = strlen(infix);

    stack *myStack = (stack *)calloc(length, sizeof(stack));
    push(myStack, '(');

    char *postfix = parseInput(myStack, infix, length);

    writeToFile(postfix, length);

    free(infix);
    free(postfix);
    free(myStack);

    return 0;
}

char * readFromFile(void)
{
    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");

    if(inputFile == NULL)
    {
        printf("File not found\n");
        return NULL;
    }
    else
    {
        fseek(inputFile, 0, SEEK_END);
        int size = ftell(inputFile);

        if(size == 0)
        {
            printf("File is empty\n");
            fclose(inputFile);
            return NULL;
        }
        else
        {
            fseek(inputFile, 0, SEEK_SET);
            int count = 0;
            char *input = (char*)calloc(size, 1);

            while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%c\n", &input[count]);;
                count++;
                if(count > size)
                {
                    printf("File contains the wrong string\n");
                    return NULL;
                }
            }

            strcat(input, ")");
            fclose(inputFile);

            return input;
        }
    }
}


void push(stack *myStack, char symb)
{
    myStack->stackArr[myStack->top] = symb;
    myStack->top++;
}

char pop(stack *myStack)
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

char getTop(stack *myStack)
{
    if (isEmpty(myStack) > 0) {
        return myStack->stackArr[myStack->top - 1];
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int isEmpty(stack *myStack)
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
    if (symb >= '0' && symb <= '9' || symb >= 'a' && symb <= 'z')
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

void writeToFile(char *postfix, int length)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");
    }
    else
    {
        int i;
        for(i = 0; i < length * 2; i++)
        {
            fprintf(file, "%c", postfix[i]);
            printf("%c", postfix[i]);
        }

        fclose(file);
    }
}

char *parseInput(stack * myStack, char *infix, int length)
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
            if (isOperator(getTop(myStack)) > 0)
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
            }
            else
            {
                push(myStack, current);
            }
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

