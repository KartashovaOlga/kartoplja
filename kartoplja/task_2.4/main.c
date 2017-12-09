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

void getNumber(char *askedNum);
boolean checkNumber(char *askedNumber);
boolean checkWin(char *inputNum, char *computerNum);
void randomCompNum(char *compNum);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    char askedNum[SIZE];
    char computerNum[SIZE] = {0};
    int isWin = FALSE;

    randomCompNum(computerNum);

    printf("Компьютер загадал целое, положительное, трехзначное число, цифры которго не повторяются.\n");
    printf("Вы должны его угадать.\nСдаться - введите <-1>\n\n*** ИГРА НАЧАЛАСЬ! ***\n\n");

    while (!isWin)
    {
        getNumber(askedNum);

        if (askedNum[0] != '-' && askedNum[1] != '1')
        {
            isWin = checkWin(askedNum, computerNum);
        }
        else
        {
            isWin = 1;
            printf("*** ВЫ СДАЛИСЬ! ***\n");
            printf("Выигрышное число - %c%c%c\n", computerNum[0], computerNum[1], computerNum[2]);
        }
    }
    
    return 0;
}

void randomCompNum(char * compNum)
{
    srand(time(NULL));
    int winNumber1;
    int winNumber2;
    int winNumber3;

    winNumber1 = 1 + rand() % 9;
    compNum[0] = winNumber1 + '0';

    winNumber2 = rand() % 10;
    while (winNumber2 == winNumber1)
    {
        winNumber2 = rand() % 10;
    }
    compNum[1] = winNumber2 + '0';

    winNumber3 = rand() % 10;
    while (winNumber3 == winNumber2 || winNumber3 == winNumber1)
    {
        winNumber3 = rand() % 10;
    }
    compNum[2] = winNumber3 + '0';
}

void getNumber(char *askedNum)
{
    printf("Ваш вариант ->");
    scanf("%s", askedNum);

    while (!checkNumber(askedNum))
    {
        printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число, цифры которго не повторяются.\n");
        printf("Ваш вариант ->");
        scanf("%s", askedNum);
    }

}

boolean checkNumber(char *askedNumber)
{
    boolean isValid = TRUE;

    if(strchr(askedNumber, 46))
    {
        isValid = FALSE;
    }
    else
    {
        int number = atoi(askedNumber);
        if(number < 100 && number != -1 || number > 999)
        {
            isValid = FALSE;
        }
        else
        {
        }
    }

    return isValid;
}

boolean checkWin(char *inputNum, char *computerNum )
{
    int i, j;
    int position = 0;
    int count = 0;
    int isWin = TRUE;

    if(memcmp(inputNum, computerNum, SIZE) == 0)
    {
        printf("Угадано 3. На своих местах 3\n");
        printf("**** ВЫ ВЫИГРАЛИ! ****\n\n");
        printf("Для завершения нажмите <Enter>\n");
        getch();
    }
    else
    {
        for(i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                if(computerNum[i] == inputNum[j])
                {
                    count++;
                    if(j == i)
                    {
                        position++;
                    }
                    else
                    {
                    }
                    break;
                }
                else
                {
                }
            }
        }

        printf("Угадано %d. На своих местах %d\n", count, position);
        isWin = FALSE;
    }
    return isWin;
 }
