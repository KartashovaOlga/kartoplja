/*
Задача 4: «Запись числа прописью»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Указание: в реализации программы используйте оператор switch.
Входные данные: oдно число - сумма (в рублях), которую необходимо записать прописью. 
Сумма представляет собой неотрицательное десятичное число, не превосходящее 999.99
(девятьсот девяносто девять рублей 99 копеек) и содержащее не более двух знаков после десятичной точки.
Незначащие ведущие нули отсутствуют.
Выходные данные: программа должна вывести запись суммы прописью. Число рублей передается соответствующим
количественным числительным, число копеек - цифрами, например: тридцать пять рублей 56 копеек. 
Запись должна быть грамматически верной. Запись всегда должна быть полной, т.е. 
включать количество рублей и копеек. Количество копеек должно быть записано двумя цифрами, 
т.е. при необходимости дополнено ведущими нулями.
 */

#include <stdio.h>
#include <windows.h>

void toString(int rub, int kop);
void getNumber(int *rub, int *kop);

int main(int argc, char** argv) 
{
    int rub;
    int kop;
    SetConsoleOutputCP(CP_UTF8);

    getNumber(&rub, &kop);
    toString(rub, kop);

    return 0;
}

void getNumber(int *rub, int *kop)
{
    float inputNumber;
    char inputBuff[7];

    printf("Enter the number:");
    scanf("%s", inputBuff);
    inputNumber = atof(inputBuff);

    while(inputNumber <= 0 || inputNumber >= 1000)
    {
        printf("You entered invalid character.\n");
        printf("Enter the number: \n");
        scanf("%s", inputBuff);
        inputNumber = atof(inputBuff);
    }

    strtok(inputBuff, ".");
    int len=  strlen(inputBuff);

    *rub = atoi(inputBuff);
    *kop = atoi(inputBuff+len+1);
}

void toString(int rub, int kop)
{
    char *outputStr[5];
    float temp = rub;

    int hundreds = temp / 100;
    int dozen = (temp - 100 * hundreds) / 10;
    int rubles = temp - 100 * hundreds - 10 * dozen;
    int kopek = kop;

    //hundreds
    switch(hundreds)
    {
        case 1: outputStr[0] = "сто"; break;
        case 2: outputStr[0] = "двести"; break;
        case 3: outputStr[0] = "триста"; break;
        case 4: outputStr[0] = "четыреста"; break;
        case 5: outputStr[0] = "пятьсот"; break;
        case 6: outputStr[0] = "шестьсот"; break;
        case 7: outputStr[0] = "семьсот"; break;
        case 8: outputStr[0] = "восемьсот"; break;
        case 9: outputStr[0] = "девятьсот"; break;
        default: outputStr[0] = ""; break;
    }

    //dozen
    switch(dozen)
    {
        case 1:
            switch (rubles)//rubles
            {
                case 0: outputStr[1] = "десять"; outputStr[2] = ""; break;
                case 1: outputStr[1] = "одиннадцать"; outputStr[2] = ""; break;
                case 2: outputStr[1] = "двенадцать"; outputStr[2] = ""; break;
                case 3: outputStr[1] = "тринадцать"; outputStr[2] = ""; break;
                case 4: outputStr[1] = "четырнадцать"; outputStr[2] = ""; break;
                case 5: outputStr[1] = "пятнадцать"; outputStr[2] = ""; break;
                case 6: outputStr[1] = "шестнадцать"; outputStr[2] = ""; break;
                case 7: outputStr[1] = "семнадцать"; outputStr[2] = ""; break;
                case 8: outputStr[1] = "восемнадцать"; outputStr[2] = ""; break;
                case 9: outputStr[1] = "девятнадцать"; outputStr[2] = ""; break;
                default:  break;
             }
            break;
        case 2: outputStr[1] = "двадцать"; break;
        case 3: outputStr[1] = "тридцать"; break;
        case 4: outputStr[1] = "сорок"; break;
        case 5: outputStr[1] = "пятьдесят"; break;
        case 6: outputStr[1] = "шестьдесят"; break;
        case 7: outputStr[1] = "семьдесят"; break;
        case 8: outputStr[1] = "восемьдесят"; break;
        case 9: outputStr[1] = "девяносто"; break;
        default: outputStr[1] = ""; break;
    }

    if(dozen != 1)
    {
        switch(rubles) // rubles
        {
            case 1: outputStr[2] = "один"; break;
            case 2: outputStr[2] = "два"; break;
            case 3: outputStr[2] = "три"; break;
            case 4: outputStr[2] = "четыре"; break;
            case 5: outputStr[2] = "пять"; break;
            case 6: outputStr[2] = "шесть"; break;
            case 7: outputStr[2] = "семь"; break;
            case 8: outputStr[2] = "восемь"; break;
            case 9: outputStr[2] = "девять"; break;
            default: outputStr[2] = ""; break;
        }
    }

    //rubles output
    if(dozen != 1 && rubles == 1)
    {
        outputStr[3] = "рубль";
    }
    else if(dozen != 1 && rubles == 2 || dozen != 1 && rubles == 3 || dozen != 1 && rubles == 4)
    {
        outputStr[3] = "рубля";
    }
    else if(dozen != 0 || rubles != 0 || hundreds != 0)
    {
        outputStr[3] = "рублей";
    }
    else
    {
        outputStr[3] = "рублей";
        outputStr[1] = "ноль";
    }
    //kopek output
    int pens = kopek;
    if(kopek > 20)
    {
        while (pens > 10)
        {
            pens = pens - 10;
        }
    }

    if(pens == 1)
    {
        outputStr[4] = "копейка";
    }
    else if(pens == 2 || pens == 3 || pens == 4)
    {
        outputStr[4] = "копейки";
    }
    else
    {
        outputStr[4] = "копеек";
    }

    if(kopek < 10 && kopek > 0)
    {
        printf("%s %s %s %s 0%d %s\n", outputStr[0], outputStr[1], outputStr[2], outputStr[3], kopek, outputStr[4]);
    }
    else if(kopek == 0)
    {
        printf("%s %s %s %s 00 %s\n", outputStr[0], outputStr[1], outputStr[2], outputStr[3], outputStr[4]);
    }
    else
    {
        printf("%s %s %s %s %d %s\n", outputStr[0], outputStr[1], outputStr[2], outputStr[3], kopek, outputStr[4]);
    }
}
