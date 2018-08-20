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

void writeToFile(const char *postfix, const int length)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");
    }
    else
    {
        int i;
        for(i = 0; i < length * MULTIPLIER; i++)
        {
            fprintf(file, "%c", postfix[i]);
            printf("%c", postfix[i]);
        }

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
