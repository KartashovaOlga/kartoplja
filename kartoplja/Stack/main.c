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
#include "Stack.h"


char * readFromFile(void);
bool checkInfix(const char *infix, const int length);
void writeToFile(const char  *postfix, const int length);
void generateReversePolishNotation(const char *infix, const int length);
bool isOperand(const char symb);
bool isOperator(const char symb);
char *parseInput(Stack_t * myStack, const char *infix, const int length);
bool getPriority(const char symb);

int main(int argc, char **argv)
{
    int length;
    char *infix = readFromFile();
    strcat(infix, ")");
    length = strlen(infix);

    generateReversePolishNotation(infix, length);

    free(infix);

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
        int size = ftell(inputFile) + 1;

         fseek(inputFile, 0, SEEK_SET);
         char *input = (char*)calloc(size, sizeof(char));

         fgets(input, size, inputFile);
         fclose(inputFile);

         return input;
    }
}

bool checkInfix(const char *infix, const int length)
{
    int i;
    bool isValid = true;

    for(i = 0; i < length; i++)
    {
        if(isOperand(infix[i])
           || isOperator(infix[i])
           || infix[i] == '('
           || infix[i] == ')'
           || infix[i] == ' ')
        {
            continue;
        }
        else
        {
            isValid = false;
            break;
        }
    }
    return isValid;
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

void writeToFile(const char *postfix, const int length)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");
    }
    else
    {
        fprintf(file, "%s", postfix);
        printf("%s", postfix);

        fclose(file);
    }
}

void generateReversePolishNotation(const char *infix, const int length)
{
    if(checkInfix(infix, length))
    {
        Stack_t *myStack = createStack();

        push(myStack, '(');

        char *postfix = parseInput(myStack, infix, length);

        writeToFile(postfix, length);

        free(postfix);
        free(myStack);
    }
    else
    {
        printf("File contains wrong string %s\n", infix);
    }
}