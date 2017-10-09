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

int convertToDecimal(int binary);
int getBinaryNum(void);
int checkNumber(int number);

int main(int argc, char** argv) {
    int binaryNumber = getBinaryNum();
    
    int decimalNumber = convertToDecimal(binaryNumber);
   
    printf("\nBinary number: %d\nDecimal number: %d", binaryNumber, decimalNumber);

    return 0;
}

int convertToDecimal(int binaryNum){
    int number, tmp;
    int decimalNumber = 0;
    float c = 0.0;
    number = binaryNum;
    
    while (number != 0) 
    {
        tmp = number % 10;
        number /= 10;
        decimalNumber += (int)powf(2.0, c) * tmp;
        c++;
    }
    return decimalNumber;
}

int getBinaryNum(void){
    char bNum[12];
    int binaryNum;
    
    printf("Enter the binary number: \n");
    gets(bNum);
    binaryNum = atoi(bNum);
    
    if(binaryNum < 0)
    {
        binaryNum = getBinaryNum();
    }
    
    return binaryNum;
}

int checkNumber(int number){
    
}
