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

int convertToDecimal(int binaryNum);
int getBinaryNum(void);

int main(int argc, char** argv) {
    int binaryNumber = getBinaryNum();

    if(binaryNumber != 0)
    {
        int decimalNumber = convertToDecimal(binaryNumber);
        printf("\nBinary number: %d\nDecimal number: %d", binaryNumber, decimalNumber);
    }else
    {
        printf("You entered a wrong number\n");
        binaryNumber = getBinaryNum();
    }

    return 0;
}

int convertToDecimal(int binaryNum){
    int number, tmp;
    int decimalNumber = 0;
    int c = 0;
    number = binaryNum;

    while (number != 0)
    {
        tmp = number % 10;
        number /= 10;
        decimalNumber += powf(2, c) * tmp;
        c++;
    }
    return decimalNumber;
}

int getBinaryNum(void){
    int binaryNum;

    printf("Enter the binary number:\n");
    scanf("%[01]", &binaryNum);

    return binaryNum;
}
