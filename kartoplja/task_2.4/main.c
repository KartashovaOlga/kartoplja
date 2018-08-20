/*
Напишите программу, которая реализует игру «Угадай число». Правила игры следующие:
Играют двое. Один задумывает число, второй – угадывает. На каждом шаге угадывающий
делает предположение,  а задумавший число –  говорит,  сколько цифр числа угаданы
и сколько из угаданных цифр занимают правильные позиции в числе.
Входные данные: предположения о загаданном числе – трехзначные целые числа.
Предусмотреть случаи некорректного ввода.
Выходные данные: сообщения об общем количестве угаданных цифр и количестве угаданных
цифр, которые находятся на своих местах.
*/

#include <stdio.h>
#include <stdbool.h>
#include <rpc.h>
#include <time.h>
#include <conio.h>

#define SIZE 10

int createCompNumber(void);
int getNumber(void);
bool guessNumIsValid(int guessNum);
bool compNumIsValid(int compNum);
void inputNumToPositionsArray(int inputNum, char *outputNum);
void theGame(int compNum);
void checkNumbersAndPositions(const char *arrayOfCompNum, const char *arrayOfGuessNum);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    static int compNum = 0;
    compNum = createCompNumber();

    printf("Компьютер загадал число.\n");
    printf("Вы должны его угадать.\nСдаться - введите <-1>\n\n*** ИГРА НАЧАЛАСЬ! ***\n\n");
    printf("Ваш вариант ->");

    theGame(compNum);

    return 0;
}

int getNumber(void)
{
    int guessNum = -1;
    scanf("%d", &guessNum);

    return  guessNum;
}

bool guessNumIsValid(int guessNum)
{
    bool isValid = false;

    if(guessNum >= 102 && guessNum <= 987)
    {
        if( guessNum % 10 == guessNum / 10 % 10
            || guessNum % 10 == guessNum / 100
            || guessNum / 10 % 10 == guessNum / 100 )
        {
            printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число, цифры которого не повторяются.\n");
            printf("Ваш вариант ->");
        }
        else
        {
            isValid = true;
        }
    }
    else
    {
        printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число, цифры которого не повторяются.\n");
        printf("Ваш вариант ->");
    }
    return isValid;
}

int createCompNumber(void)
{
    srand(time(NULL));

    int compNum = 0;

    while (compNumIsValid(compNum))
    {
        compNum = 100 + rand() % 900;
    }

    return compNum;
}

bool compNumIsValid(int compNum)
{
    bool isValid = false;

    if( compNum % 10 == compNum / 10 % 10
        || compNum % 10 == compNum / 100
        || compNum / 10 % 10 == compNum / 100 )
    {
        isValid = true;
    }
    else
    {
    }

    return isValid;
}

void inputNumToPositionsArray(int inputNum, char *outputNum)
{
    int century = inputNum / 100;
    int decade = inputNum / 10 % 10;
    int units = inputNum % 10;

    memset(outputNum, 0, SIZE);

    outputNum[century] = 3;
    outputNum[decade] = 2;
    outputNum[units] = 1;
}

void checkNumbersAndPositions(const char *arrayOfCompNum, const char *arrayOfGuessNum)
{
    int count = 0;
    int position = 0;
    int i;

    for(i = 0; i < SIZE; i++)
    {
        if(count == 3)
        {
            break;
        }
        else if(arrayOfGuessNum[i] != 0 && arrayOfCompNum[i] != 0)
        {
            count++;
            if(arrayOfGuessNum[i] == arrayOfCompNum[i])
            {
                position++;
            }
            else
            {
            }
        }
        else
        {
        }
    }

    printf("Угадано %d. На своих местах %d\n", count, position);
    printf("Ваш вариант ->");
}

void theGame(int compNum)
{
    bool isWin = false;
    char arrayOfCompNum[SIZE] ;
    char arrayOfGuessNum[SIZE];
    int guessNum;

    inputNumToPositionsArray(compNum, arrayOfCompNum);

    while(!isWin)
    {
        guessNum = getNumber();

        if(guessNum == -1)
        {
            isWin = true;
            printf("*** ВЫ СДАЛИСЬ! ***\n");
            printf("Победное число - %d\n", compNum);
        }
        else if(guessNumIsValid(guessNum))
        {
            if(guessNum == compNum)
            {
                isWin = true;
                printf("Угадано 3. На своих местах 3\n");
                printf("**** ВЫ ВЫИГРАЛИ! ****\n\n");
                printf("Для завершения нажмите <Enter>\n");
                getch();
            }
            else
            {
                inputNumToPositionsArray(guessNum, arrayOfGuessNum);

                checkNumbersAndPositions(arrayOfCompNum, arrayOfGuessNum);
            }
        }
    }
}
