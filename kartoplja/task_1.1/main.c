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

size_t getNumber(void);
void printSquare(const size_t length);

int main(int argc, char** argv) 
{
    size_t length = getNumber();
     
    printSquare(length);
         
    return (EXIT_SUCCESS);
}

size_t getNumber(void)
{
    size_t number;  
    
    printf("Enter the square's side length:\n");
    scanf("%u", &number);

    while(number > 80 || number < 0)
    {
       printf("You entered an invalid character\n");
       printf("Enter the square's side length:\n");
       
       scanf("%u", &number);
    }
    
    return number;
}

void printSquare(const size_t length)
{
  int i, j;
    
    for(i = 0; i < length; i++)
    {
        if(i == 0 || i == length -1)
        {
            for(j = 0; j < length; j++)
            {
                printf("*");
            }
        }
        else
        {
            for(int j = 0; j < length; j++)
            {
                if(j == 0 || j == length -1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
       printf("\n");
    }  
}
