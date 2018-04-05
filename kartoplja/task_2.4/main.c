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
boolean checkValid(int winNumber);

int main()
{


    SetConsoleOutputCP(CP_UTF8);

    char askedNum[SIZE];
    char computerNum[SIZE] = {0};
    int isWin = FALSE;

    randomCompNum(computerNum);

    printf("Компьютер загадал число.\n");
    printf("Вы должны его угадать.\nСдаться - введите <-1>\n\n*** ИГРА НАЧАЛАСЬ! ***\n\n");

    while (!isWin)
    {
        getNumber(askedNum);

        if (askedNum[0] == '-' && askedNum[1] == '1')
        {
            isWin = TRUE;
            printf("*** ВЫ СДАЛИСЬ! ***\n");
            printf("Выигрышное число - %c%c%c\n", computerNum[0], computerNum[1], computerNum[2]);
        }
        else
        {
            isWin = checkWin(askedNum, computerNum);
        }
    }



    return 0;
}

void randomCompNum(char * compNum)
{
    srand(time(NULL));

    int winNumber = 0;

    while (!checkValid(winNumber))
    {
        winNumber = 100 + rand() % 900;
    }

    itoa(winNumber, compNum, 10);

}

void getNumber(char *askedNum)
{
    printf("Ваш вариант ->");
    scanf("%s", askedNum);

    while (!checkNumber(askedNum))
    {
        printf("Вы ввели некорректные данные. Введите целое, положительное, трехзначное число, цифры которого не повторяются.\n");
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
    clock_t start = clock();
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

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

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
