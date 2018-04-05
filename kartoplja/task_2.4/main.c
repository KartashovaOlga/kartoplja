/*
Напишите программу, которая реализует игру «Угадай число». Правила игры следующие. 
Играют двое. Один задумывает число, второй – угадывает. На каждом шагеу гадывающий 
делает предположение,  а задумавший число –  говорит,  сколько цифр числа угаданы
и сколько из угаданных цифр занимают правильные позиции в числе.  Например,   если 
задуманное число 725 и выдвинуто предположение, что задумано число 523, то угаданы 
две цифры (5 и 2) и одна из них (2) занимает верную позицию. 
Указание. Изучите функции cprintf,  textcolor,  textbackground. Используйте их в своей 
программе. 
Входные данные: предположения о загаданном числе – трехзначны ецелые числа. 
Предусмотреть случаи некорректного ввода. 
Выходные данные: сообщения об общем количестве угаданных цифр и количестве угаданных 
цифр, которые находятся на своих местах. 
*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define SIZE 3

int getNumber(void);
boolean checkNumber(char *askedNumber, int *guessNum);
boolean checkWin(int guessNumber, int randNumber, char *compNum);
int randomCompNum(void);
boolean checkValid(int winNumber);
void toArray(int inputNum, char *outputNum);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int isWin = FALSE;
    char compNum[10];
    int guessNumber = 0;
    int randNumber = randomCompNum();

    toArray(randNumber, &compNum);

    printf("Компьютер загадал число.\n");
    printf("Вы должны его угадать.\nСдаться - введите <-1>\n\n*** ИГРА НАЧАЛАСЬ! ***\n\n");

    while (!isWin)
    {
        guessNumber = getNumber();

        if (guessNumber == -1)
        {
            isWin = TRUE;
            printf("*** ВЫ СДАЛИСЬ! ***\n");
            printf("Выигрышное число - %d\n", randNumber);
        }
        else
        {
            isWin = checkWin(guessNumber, randNumber, compNum);
        }
    }

    return 0;
}

int randomCompNum(void)
{
    srand(time(NULL));

    int winNumber = 0;

    while (!checkValid(winNumber))
    {
        winNumber = 100 + rand() % 900;
    }

    return winNumber;
}

int getNumber(void)
{
    char *askedNum;
    int guessNum = 0;

    printf("Ваш вариант ->");
    scanf("%s", &askedNum);

    while (!checkNumber(&askedNum, &guessNum))
    {
        printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число, цифры которого не повторяются.\n");
        printf("Ваш вариант ->");
        scanf("%s", &askedNum);
    }

    return  guessNum;
}

boolean checkNumber(char *askedNumber, int *guessNum)
{
    boolean isValid = TRUE;

    if(strchr(askedNumber, 46))
    {
        isValid = FALSE;
    }
    else
    {
        *guessNum = atoi(askedNumber);

        if(*guessNum < 100 && *guessNum != -1 || *guessNum > 999)
        {
            isValid = FALSE;
        }
        else
        {
        }
    }

    return isValid;
}

boolean checkWin(int guessNumber, int randNumber, char * compNum)
{
    int i;
    int position = 0;
    int count = 0;
    int isWin = TRUE;
    int length = 10;
    char inputNum[length];

    if(guessNumber == randNumber)
    {
        printf("Угадано 3. На своих местах 3\n");
        printf("**** ВЫ ВЫИГРАЛИ! ****\n\n");
        printf("Для завершения нажмите <Enter>\n");
        getch();
    }
    else
    {
        toArray(guessNumber, &inputNum);

        for(i = 0; i < length; i++)
        {
            if(inputNum[i] != 0 && compNum[i] != 0)
            {
                count++;
                if(inputNum[i] == compNum[i])
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
        isWin = FALSE;
    }

    return isWin;
 }

boolean checkValid(int winNumber)
{
    if( winNumber % 10 == winNumber / 10 % 10
        || winNumber % 10 == winNumber / 100
        || winNumber / 10 % 10 == winNumber / 100 )
    {
        return FALSE;
    }
    else
    {
        return  TRUE;
    }
}

void toArray(int inputNum, char *outputNum)
{
    int i;
    int j;
    char num[SIZE];
    char checkNumbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    itoa(inputNum, num, 10);

    for (i = 0; i < 10; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(num[j] == checkNumbers[i])
            {
                outputNum[i] = j + 1;
                break;
            }
            else
            {
                outputNum[i] = 0;
            }
        }
    }
}
