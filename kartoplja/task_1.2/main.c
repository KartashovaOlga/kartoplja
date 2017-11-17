/*
Задача 2: «Двоичное число»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Введите целое число в двоичной системе счисления и выведите его десятичный эквивалент.
Указание. Примените операции деления (/) и взятия по модулю (%) для отделения справа налево одного за другим «двоичного» числа.
Входные данные: oдно целое число.
Выходные данные: десятичное представление введенного числа.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

void convertToDecimal(char *binaryNum, int result);
void getBinaryNum(char *bNum);
int isBinary(char *binaryNum);

int main(int argc, char** argv) 
{
    char *binaryNum;
    
    getBinaryNum(binaryNum);
    
    int result = isBinary(binaryNum);

    if(result > 0)
    {
        convertToDecimal(binaryNum, result);
    }
     else
    {
        printf("You entered a wrong number\n");
    }
    return 0;
}

void convertToDecimal(char *binaryNum, int result)
{
    int i, count = 0;
    int decimalNumber = 0;
    for(int i = strlen(binaryNum) - 1; i >= 0; i--)
    {
        if(binaryNum[i] == '1')
        {
            decimalNumber += powf(2, count);
            count++;
        }
        else
        {
            count++;
        }
    } 

    printf("Binary number: %s\nDecimal number: %d", binaryNum, decimalNumber);
}

void getBinaryNum(char *bNum)
{
    printf("Enter the binary number:\n");
    scanf("%s", bNum);
}

int isBinary(char *binaryNum)
{
    int i;
    for(i = 0; i < strlen(binaryNum); i ++)
    {
        if(binaryNum[i] != '1' && binaryNum[i] != '0')
        {
            return -1;
            break;
        }
        else
        {          
        }
    }
    return 1;
}
