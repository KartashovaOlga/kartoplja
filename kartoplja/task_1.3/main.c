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
#include <stdlib.h>

int factorial(int i);
double getNumber(void);
double calculateExp(const double precision);
void printExp(const double exp, int reqPrecision);
int getPrecision(double input);

int main(int argc, char** argv) 
{
    double precision = getNumber();  
    

    double exp = calculateExp(precision);
  
    int reqPrecision = getPrecision(precision);
    
    printExp(exp, reqPrecision);
    
    return 0;
}

int factorial(int i)
{
    if(i <= 1)
    {
        return 1;
    }
    return i * factorial(i-1);
}

double getNumber(void)
{
    double number;

    printf("Enter the required precision: \n");
    scanf("%lf", &number);
    
    while(number >= 1 || number <= 0)
    {
        printf("You entered an invalid character\n");
        printf("Enter the required precision: \n");
        scanf("%lf", &number);
    }
    
    return number;
}

double calculateExp(const double precision)
{
    double temp = 1.0;
    double exp = 1.0;   
    int num = 1;
    
    while(temp >= precision)
    {
        temp = 1.0 / factorial(num);
        exp += temp ;
        num++;
    }
    
    return exp;
}

void printExp(const double exp, int n)
{  
    char buff[200];
    sprintf(buff, "%.*f", n, exp); 
    printf("Exponent =  %s", buff);
}

int getPrecision(double input)
{
    int count  = 0;
    double temp = input;
   
    while(temp < 1)
    {
       temp *= 10;
       count++;
    }
    return count;
}
