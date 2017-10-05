/*
Задача 2: «Двоичное число»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Введите целое число в двоичной системе счисления и выведите его десятичный эквивалент.
Указание. Примените операции деления (/) и взятия по модулю (%) для отделения справа налево одного за другим «двоичного» числа.
Входные данные: oдно целое число.
Выходные данные: десятичное представление введенного числа.
 */

/* 
 * File:   main.c
 * Author: IS
 *
 * Created on 1 октября 2017 г., 12:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int binaryNumber;
    
    printf("Enter the binary number: ");
    scanf("%d", &binaryNumber);
    
    while(binaryNumber < 0){
        printf("Enter the binary number: ");
        scanf("%d", &binaryNumber);
    }
    int number, tmp, decimalNumber = 0;
    float c = 0.0;
    number = binaryNumber;
    while (number != 0) {
        tmp = number % 10;
        number /= 10;
        decimalNumber += (int)powf(2.0, c) * tmp;
        c++;
        
        
        /*if(number %10 != 0 ){
                number /= 10;
                decimalNumber += (int)powf(2.0, c);
                c++;
            }else{
                number /= 10;
                c++;
            }*/
	}
	printf("\nBinary number: %d\nDecimal number: %d", binaryNumber, decimalNumber);

    return (EXIT_SUCCESS);
}

