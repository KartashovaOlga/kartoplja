/*
Задача 3: «Вычисление экспоненты»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
Напишите программу, которая оценивает значение е с заданной точностью е (0 <е < 1). 
Примечание. е = 2.718281828459...
Указание. Изучите преобразование типов данных в языке Си.
Входные данные: oдно действительное число е (0 <е< 1). 
Выходные данные: oдно действительное число - значение константы е.
*/


#include <stdio.h>

int factorial(int i);
float getNumber(void);
double calculateExp(float precision);

int main(int argc, char** argv) 
{
    float precision = getNumber();
    
    while(precision >= 1 || precision <= 0)
    {
        precision = getNumber();
    }
    
    double exp = calculateExp(precision);
    
    printf("Exponent = %lf", exp);       

    return 0;
}

int factorial(int i){
    if(i <= 1)
    {
        return 1;
    }
    return i * factorial(i-1);
}

float getNumber(void)
{
    float i;  
    printf("Enter the square's side length: \n");
    scanf("%f", &i);
    return i;
}

double calculateExp(float precision){
    double temp = 1.0;
    double exp = 1.0;   
    int num = 1;
    while(temp > precision)
    {
        temp = 1.0 / (double) factorial(num);
        exp += temp ;
        num++;
    }
    return exp;
}
