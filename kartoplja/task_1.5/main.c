/*
Дополнительная задача *: «Пифагоровы тройки»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Прямоугольный треугольник может иметь стороны, каждая из которых является целым числом. 
Набор трех целочисленных значений для сторон прямоугольного треугольника называется пифагоровой тройкой. 
Эти три стороны должны удовлетворять следующему соотношению: сумма квадратов двух катетов равна квадрату гипотенузы. 
Напишите программу, которая выводит все пифагоровы тройки для катетов и гипотенузы, не превосходящих целого числа п.
Указание. Используйте цикл с тройной вложенностью, в котором перебираются все возможности. 
Определите количество операций в таком цикле. Можно ли сократить количество операций?
Входные данные: oдно целое число п.
Выходные данные: все пифагоровы тройки для катетов и гипотенузы в виде таблицы.
 */

/* 
 * File:   main.c
 * Author: IS
 *
 * Created on 3 октября 2017 г., 19:46
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int leg1, leg2, hypotenuse, length;
    
    printf("Enter the max length of the triangle side: \n");
    scanf("%d", &length);
    
    while(length < 0){
       printf("Enter the max length of the triangle side: \n");
       scanf("%d", &length); 
    }
    
    printf("Leg 1  Leg 2  Hypotenuse\n");
    
    for(hypotenuse = 1; hypotenuse <= length; hypotenuse++){
        for(leg1 = 1; leg1 <= length; leg1++){
            for(leg2 = 1; leg2 <= length; leg2++){
                
                if(hypotenuse*hypotenuse == ((leg1*leg1) + (leg2*leg2))){
                    printf("%d\t%d\t%d\n", leg1, leg2, hypotenuse);
                }
            }
        }
    }

    return (EXIT_SUCCESS);
}

