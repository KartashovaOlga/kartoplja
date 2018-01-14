/*
Напишите программу,  которая вычисляет сумму покупки,  складывающуюся из суммы 
стоимости товаров,  и печатает ее на чеке,  вставляя, при необходимости,  символы 
звездочек. 
Указание. Изучитефункцииработысостроками. Обратите внимание на функцию sprintf. 
Входные данные: в каждой строке файла записано одно вещественное число – стоимость товара. 
Выходные данные: чек в следующем формате: первая строка  – в девяти полях сумма покупки,при 
необходимости,  вставить разделительный апостроф на  3-ю позицию и дополнить
звездочками. Вторая строка – девять символов тире. Третья строка – позиции цифр. 
*/

#include <stdio.h>
#include <mem.h>

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
    if(summ > 0)
    {
        FILE *file = fopen("c:\\Temp\\output.txt", "w");

        if(file == NULL)
        {
            printf("File was not created\n");
        }
        else
        {
            if(summ >= 100000)
            {
                fprintf(file, "The sum contains more then 9 numerals\n");
            }
            else
            {
                char sumStr[] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
                int size = 9;

                char result[9];
                sprintf(result, "%.2f", summ);

                int i;
                int j;

                if(summ >= 1000)
                {
                    for(i = size, j = strlen(result); i >= 0, j >= 0; i--, j--)
                    {
                        if(i == 2){
                            sumStr[i] = '\'';
                            i--;
                            sumStr[i] = result[j];
                        }
                        else
                        {
                            sumStr[i] = result[j];
                        }
                    }
                }
                else
                {
                    for(i = size, j = strlen(result); i >= 0, j >= 0; i--, j--)
                    {
                        sumStr[i] = result[j];
                    }
                }

                fprintf(file, "%s\n", sumStr);
                fprintf(file, "%s\n", "---------");
                fprintf(file, "%s", "123456789");
            }

            fclose(file);
        }
    }
    else
    {
        printf("File contains wrong string\n");
    }
}
