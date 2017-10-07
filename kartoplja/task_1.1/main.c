/*
Задача 1: «Квадрат»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Напишите программу, которая считывает размер стороны квадрата и затем выводит полый квадрат в виде звездочек.
Входные данные: oдно целое число - размер стороны квадрата - из отрезка от 0 до 80.
Выходные данные: pисунок полого квадрата в виде звездочек.
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int length;
    
    printf("Enter the square's side length: \n");
    scanf("%d", &length);
    
    while(length > 80 || length < 0){
        printf("Enter the square's side length: \n");
        scanf("%d", &length);
    }
    
    for(int i = 0; i < length; i++){
        if(i == 0 || i == length -1){
            for(int j = 0; j < length; j++){
                printf("*");
            }
       }else{
            for(int j = 0; j < length; j++){
                if(j == 0 || j == length -1){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
       }
       printf("\n");
    }
     
    return (EXIT_SUCCESS);
}
