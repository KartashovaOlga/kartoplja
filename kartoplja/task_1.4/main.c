/*
Задача 4: «Запись числа прописью»
Входные данные: вводятся с клавиатуры
Выходные данные: выводятся на экран
В бухгалтерской деятельности, да и не только в ней, часто возникает необходимость 
записать некоторую денежную сумму прописью. Правила русского языка в данном случае относительно просты,
и поэтому такая задача может быть поручена компьютеру. 
Указание: в реализации программы используйте оператор switch.
Входные данные: oдно число - сумма (в рублях), которую необходимо записать прописью. 
Сумма представляет собой неотрицательное десятичное число, не превосходящее 999.99 
(девятьсот девяносто девять рублей 99 копеек) и содержащее не более двух знаков после десятичной точки.
Незначащие ведущие нули отсутствуют.
Выходные данные: программа должна вывести запись суммы прописью. Число рублей передается соответствующим
количественным числительным, число копеек - цифрами, например: тридцать пять рублей 56 копеек. 
Запись должна быть грамматически верной. Запись всегда должна быть полной, т.е. 
включать количество рублей и копеек. Количество копеек должно быть записано двумя цифрами, 
т.е. при необходимости дополнено ведущими нулями.
 */

#include <stdio.h>

void toString(float input);
float getNumber(void);

int main(int argc, char** argv) 
{
    float number = getNumber();
            
    toString(number);
    
    return 0;
}

void toString(float input)
{
    char *str [5];
    
    int temp = input;
    int hundreds = temp/100;
    
    switch(hundreds)
    {
        case 1: str[0] = "сто "; break;
        case 2: str[0] = "двести "; break;
        case 3: str[0] = "триста "; break;
        case 4: str[0] = "четыреста "; break;
        case 5: str[0] = "пятьсот "; break;
        case 6: str[0] = "шестьсот "; break;
        case 7: str[0] = "семьсот "; break;
        case 8: str[0] = "восемьсот "; break;
        case 9: str[0] = "девятьсот "; break;
        case 0: str[0] = ""; break;
    }
    
    int dozens = (temp - hundreds*100) / 10;
    int rubles = temp - hundreds*100 - dozens*10;

    switch(dozens)
    {
        case 1: switch (rubles)
                {
                case 0: str[1] = "десять "; str[2] = ""; break;
                case 1: str[1] = "одиннадцать "; str[2] = ""; break;
                case 2: str[1] = "двенадцать "; str[2] = ""; break;
                case 3: str[1] = "тринадцать "; str[2] = ""; break;
                case 4: str[1] = "четырнадцать "; str[2] = ""; break;
                case 5: str[1] = "пятнадцать "; str[2] = ""; break;
                case 6: str[1] = "шестнадцать "; str[2] = ""; break;
                case 7: str[1] = "семнадцать "; str[2] = ""; break;
                case 8: str[1] = "восемнадцать "; str[2] = ""; break;
                case 9: str[1] = "девятнадцать "; str[2] = ""; break;
                } break;
        case 2: str[1] = "двадцать "; break;
        case 3: str[1] = "тридцать "; break;
        case 4: str[1] = "сорок "; break;
        case 5: str[1] = "пятьдесят "; break;
        case 6: str[1] = "шестьдесят "; break;
        case 7: str[1] = "семьдесят "; break;
        case 8: str[1] = "восемьдесят "; break;
        case 9: str[1] = "девяносто "; break;
        case 0: str[1] = ""; break;
    }
        
    if(dozens == 0 || dozens >= 2)
    {      
      switch(rubles)
      {
         case 1: str[2] = "один "; break;
         case 2: str[2] = "два "; break;
         case 3: str[2] = "три "; break;
         case 4: str[2] = "четыре "; break;
         case 5: str[2] = "пять "; break;
         case 6: str[2] = "шесть "; break;
         case 7: str[2] = "семь "; break;
         case 8: str[2] = "восемь "; break;
         case 9: str[2] = "девять "; break;   
         case 0: str[2] = ""; break;
      }
    }  
    
    if(rubles == 1 && dozens != 1)
    {
       str[3] = "рубль ";
    }
    else if(rubles > 1 && rubles < 5  && dozens != 1)
    {
       str[3] = "рубля ";
    }
    else
    {
        str[3] = "рублей "; 
    }
    
    int pennies = (input - temp) * 100;
    int kopek = pennies;
       
    if(pennies > 20 )
    {
        while(kopek > 10)
        {
            kopek -= 10;
        }
    }
    else
    {
        
    }    
    
    if(kopek == 1)
    {
        str[4] = " копейка";
    }
    else if(kopek > 1 && kopek < 5)
    {
        str[4] = " копейки";
    }
    else
    {
        str[4] = " копеек";
    }
    
    int zero = 0;
    if(pennies < 10 && pennies > 0)
    {
       printf("%s%s%s%s%d%d%s\n", str[0], str[1], str[2], str[3], zero, pennies, str[4]); 
    }
    else if(pennies == 0)
    {
        printf("%s%s%s%s%d%d%s\n", str[0], str[1], str[2], str[3], zero, zero, str[4]); 
    }
    else
    {
        printf("%s%s%s%s%d%s\n", str[0], str[1], str[2], str[3], pennies, str[4]); 
    }               
}

float getNumber(void)
{
    float number;
    printf("Enter the number: \n");
    scanf("%f", &number);
    
    while(number <= 0 || number >= 999.99)
    {
       printf("You entered invalid character\n");
       printf("Enter the number: \n");
       scanf("%f", &number);
    }
    return number;
}
