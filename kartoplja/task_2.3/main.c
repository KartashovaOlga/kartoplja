/*
Напишитепрограмму,  которая вычисляет сумму покупки,  складывающуюся из суммы 
стоимости товаров,  и печатает ее на чеке,  вставляя, при необходимости,  символы 
звездочек. 
Указание. Изучитефункцииработысостроками. Обратитевниманиенафункцию sprintf. 
Входныеданные: в каждой строке файла записано одно вещественное число – стоимостьтовара. 
Выходныеданные: чек в следующем формате:     первая строка  – в девяти полях сумма покупки,    при 
необходимости,  вставить разделительный апостроф на  3-ю позицию и дополнить 
звездочками. Втораястрока – девятьсимволовтире. Третьястрока – позициицифр. 

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float  readFromFile(void);
void writeToFile(float summ);


int main(int argc, char** argv)
{
    float summ = readFromFile();
    writeToFile(summ);
    
    return 0;
}

float readFromFile(void)
{
    int count = 0;
    float f = 0;
    float summ = 0;

    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");

    if(inputFile == NULL)
    {
        printf("File not found\n");
        return  0;
    }
    else
    {
        fseek(inputFile, 0, SEEK_END);
        unsigned int size = ftell(inputFile);

        if(size == 0)
        {
            printf("File is empty\n");
            fclose(inputFile);

            return 0;
        }
        else
        {
            fseek(inputFile, 0, SEEK_SET);
            
            
             while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%f\n", &f);
                summ += f;
                count++;
                if(count > size)
                {
                    printf("File contains wrong string\n");
                    summ = -1;
                    break;
                }
            }
            fclose(inputFile);
            
            return summ;
        }
    }
}

void writeToFile(float summ)
{
    char str[] = "---------";
    char position[] = "123456789";
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");

    } 
    else
    {
        fprintf(file, "%0*.*f\n", 9, 2, summ);
        fprintf(file, "%s\n", str);
        fprintf(file, "%s", position);
        
        fclose(file);
    }
}
