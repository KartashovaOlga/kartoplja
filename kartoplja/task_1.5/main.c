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

#include <stdio.h>

int getNumber(void);
void pythagoreanTriplets(int length);

int main(int argc, char** argv) {
    int length = getNumber();
        
    while(length < 0)
    {
      length = getNumber();
    }
    
    pythagoreanTriplets(length);
    
    return 0;
}

int getNumber(void){
    int length;
    printf("Enter the max length of the triangle side: \n");
    scanf("%d", &length);
    return length;
}

void pythagoreanTriplets(int length){
    int leg1, leg2, hypotenuse;
    
    printf("Leg 1\tLeg 2\tHypotenuse\n");
    
    for(hypotenuse = 1; hypotenuse <= length; hypotenuse++)
    {
        for(leg1 = 1; leg1 <= length; leg1++)
        {
            for(leg2 = 1; leg2 <= length; leg2++)
            {
                if(hypotenuse*hypotenuse == ((leg1*leg1) + (leg2*leg2)))
                {
                    printf("%d\t%d\t%d\n", leg1, leg2, hypotenuse);
                }
            }
        }
    }
}
