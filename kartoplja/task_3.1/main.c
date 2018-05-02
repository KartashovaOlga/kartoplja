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
int checkInfix(char *infix, int length);
void writeToFile(char  *postfix, int length);

int main(int argc, char **argv)
{
    int length;

    char *infix = readFromFile();
    length = strlen(infix);

    if(checkInfix(infix, length) > 0)
    {
        Stack_t *myStack = (Stack_t*)malloc(sizeof(char));
        push(myStack, '(');

        char *postfix = parseInput(myStack, infix, length);

        writeToFile(postfix, length);

        free(postfix);
        free(myStack);
    }
    else
    {
        printf("File contains wrong string\n");
    }

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
            char *input = (char*)calloc(size, 1);

            fgets(input, size, inputFile);

            strcat(input, ")");
            fclose(inputFile);

            return input;
        }
    }
}

int checkInfix(char *infix, int length)
{
    int i;
    int isValid = 1;
    for(i = 0; i < length; i++)
    {
       if(isOperand(infix[i]) > 0
          || isOperator(infix[i]) > 0
          || infix[i] == '('
          || infix[i] == ')'
          || infix[i] == ' ')
       {
           continue;
       }
       else
       {
           isValid = -1;
       }
    }
    return isValid;
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

