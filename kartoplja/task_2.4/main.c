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

void getNumber(char *askedNum);
boolean checkNumber(char *askedNumber);
void checkWin(char *inputNum, char *computerNum);
void randomCompNum(char *computerNum);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("Компьютер загадал целое, положительное, трехзначное число. Вы должны его угадать.\n*** ИГРА НАЧАЛАСЬ! ***\n\n");

    char computerNum[3];
    char askedNum[4];

    randomCompNum(computerNum);
    getNumber(askedNum);
    checkWin(askedNum, computerNum);

    return 0;
}

void randomCompNum(char *computerNum)
{
    srand(time(NULL));
    int winNumber = 100 + rand() % 999;
    itoa(winNumber, computerNum,10);
}

void getNumber(char *askedNum)
{
    printf("Ваш вариант ->");
    scanf("%s", askedNum);

    while (!checkNumber(askedNum))
    {
        printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число.\n");
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
        if(number < 100 || number > 999)
        {
            isValid = FALSE;
        }
        else
        {
        }
    }

    return isValid;
}

void checkWin(char *inputNum, char *computerNum )
{
    int i, j;
    int position = 0;
    int count = 0;

    if(strcmp(inputNum, computerNum) == 0)
    {
        printf("Угадано 3. На своих местах 3\n");
        printf("**** ВЫ ВЫИГРАЛИ! ****\n\n");
        printf("Для завершения нажмите <Enter>\n");
        getch();
    }
    else
    {
        for(i = 0; i < strlen(computerNum); i++)
        {
            for (j = 0; j < strlen(inputNum); j++)
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
        getNumber(inputNum);
        checkWin(inputNum, computerNum);
    }
 }